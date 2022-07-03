#include <iostream>

#include "engine/window/Window.h"

#include "engine/renderer/Renderer.h"
#include "engine/renderer/TrackballCamera.h"
#include "engine/renderer/TextureRenderer.h"

#include "ImguiStyles.h"

// ImGui funcs
void dockSpace(bool* p_open);
// Window callbacks
void resizeFun(GLFWwindow* window, int width, int height);

// Texture renderer
TextureRenderer textureRenderer;

int main(void) {

    Window window("WaveLab", 1080, 720);
    window.setResizeFun(resizeFun);

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

    // Camera
    TrackballCamera camera = TrackballCamera::perspectiveCamera(glm::radians(45.0f), window.getWidth() / window.getHeight(), 0.1, 1000);
    camera.zoom(-5.5);
    camera.setTheta(M_PI / 4); camera.setPhi(M_PI / 1.5);
    float sensitivity = 1.5f, panSensitivity = 1.0f, zoomSensitivity = 1.0f;
    renderer.setCamera(camera);

    // Light
    Light light(glm::vec3(2, -8, 5));
    renderer.setLight(light);
    renderer.disableLight();
    
    // Cube polytope -> Vertex: x y z r g b nx ny nz
    std::vector<Vec3f> vertices = {
        // Back face
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f), // Bottom-left
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f), // top-right
        Vec3f( 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f), // bottom-right         
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f), // top-right
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f), // bottom-left
        Vec3f(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f), // top-left
        // Front face
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,  1.0f), // bottom-left
        Vec3f( 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,  1.0f), // bottom-right
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f), // top-right
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f), // top-right
        Vec3f(-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,  1.0f), // top-left
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,  1.0f), // bottom-left
        // Left face
        Vec3f(-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f), // top-right
        Vec3f(-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f), // top-left
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f), // bottom-left
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f), // bottom-left
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f), // bottom-right
        Vec3f(-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f), // top-right
        // Right face
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f), // top-left
        Vec3f( 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f), // bottom-right
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f), // top-right         
        Vec3f( 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f), // bottom-right
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f), // top-left
        Vec3f( 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f,  0.0f,  0.0f), // bottom-left     
        // Bottom face
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f), // top-right
        Vec3f( 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f), // top-left
        Vec3f( 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f), // bottom-left
        Vec3f( 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f), // bottom-left
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, -1.0f,  0.0f), // bottom-right
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f), // top-right
        // Top face
        Vec3f(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f), // top-left
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  1.0f,  0.0f), // bottom-right
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f), // top-right     
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  1.0f,  0.0f), // bottom-right
        Vec3f(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f), // top-left
        Vec3f(-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  1.0f,  0.0f) // bottom-left
    };
    Polytope cubePolytope(vertices);

    Polytope cubePolytope2(vertices);
    cubePolytope2.translate(glm::vec3(1.5f, -1.5f, 0.f));
    cubePolytope2.rotate(45, glm::vec3(0, 0, 1));
    cubePolytope2.scale(glm::vec3(0.25, 0.25, 0.25));

    Group group;
    group.setLineWidth(2.f);
    group.translate(glm::vec3(0, -0.5f, 0));
    group.add(cubePolytope);
    group.add(cubePolytope2);
    renderer.addGroup(group);

    // Grid polytope
    std::vector<Vec3f> gridVertices = {};
    float a = -20; float b = 20;
    float c = -20; float d = 20;
    float dx = 0.5f; float dz = 0.5f;
    while(a <= b) {
        gridVertices.push_back(Vec3f(a, 0, c, 0.3, 0.3, 0.3));
        gridVertices.push_back(Vec3f(a, 0, d, 0.3, 0.3, 0.3));
        a += dx;
    }
    a = -b;
    while(c <= d) {
        gridVertices.push_back(Vec3f(a, 0, c, 0.3, 0.3, 0.3));
        gridVertices.push_back(Vec3f(b, 0, c, 0.3, 0.3, 0.3));
        c += dz;
    }
    Polytope gridPolytope(gridVertices);

    Group groupGrid(GL_LINES);
    groupGrid.add(gridPolytope);
    renderer.addGroup(groupGrid);

    // Init TextureRenderer
    textureRenderer = TextureRenderer(window.getWidth(), window.getHeight());

    // Enable back face culling
    renderer.enableBackFaceCulling();

    // Main loop
    while (!window.windowShouldClose()) {

        // Clear
        renderer.clear();
        // Draw to texture instead of default
        textureRenderer.renderToTexture();
        // Render
        renderer.render();
        // Go back to default
        textureRenderer.renderToDefault();

        // Rotate cubePolytope2
        cubePolytope2.rotate(1, glm::vec3(1, 0, 1));

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
                ImGui::Begin("Main Window");                         
                ImGui::TextColored(ImColor(200, 150, 255), "Main window controls");

                ImGui::Separator();

                if (ImGui::Button("Visible")) group.setVisible(!group.isVisible());
                ImGui::SameLine();
                if (ImGui::Button("Show wire")) group.setShowWire(!group.isShowWire());

                ImGui::Separator();

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
            }
            // Lighting window
            {
                ImGui::Begin("Lighting"); 
                ImGui::TextColored(ImColor(200, 150, 255), "Light configuration");
                ImGui::Text("Controls for your custom application");

                static bool enable = false;
                ImGui::Checkbox("Enable lighting", &enable);
                renderer.setLightEnabled(enable);

                static float ambientStrength = light.getAmbientStrength();
                ImGui::SliderFloat("Ambient strength", &ambientStrength, 0.f, 1.f);
                light.setAmbientStrength(ambientStrength);

                static float specularStrength = light.getSpecularStrength();
                ImGui::SliderFloat("Specular strength", &specularStrength, 0.f, 1.f);
                light.setSpecularStrength(specularStrength);

                static float color[3] = {1, 1, 1};
                ImGui::ColorEdit3("Light color", color, 0);
                light.setLightColor(glm::vec3(color[0], color[1], color[2]));

                static float lx = light.getLightPosition().x;
                static float ly = light.getLightPosition().y;
                static float lz = light.getLightPosition().z;

                ImGui::Text("Light position");
                ImGui::SliderFloat("x:", &lx, -50.f, 50.f);
                ImGui::SliderFloat("y:", &ly, -50.f, 50.f);
                ImGui::SliderFloat("z:", &lz, -50.f, 50.f);
                light.setLightPosition(glm::vec3(lx, ly, lz));

                ImGui::Separator();

                if (ImGui::Button("Reset lighting")) {
                    lx = 2; ly = -8; lz = 5;
                    ambientStrength = 0.1f;
                    specularStrength = 0.5f;
                }

                ImGui::End();
            }
            // Camera Window
            {
                ImGui::Begin("Camera");       

                ImGui::TextColored(ImColor(200, 150, 255), "Camera options");
                ImGui::Text("Camera sensitivity");

                ImGui::Separator();

                ImGui::SliderFloat("Sensitivity", &sensitivity, 0.01f, 50.f);
                ImGui::SliderFloat("Pan sensitivity", &panSensitivity, 0.01f, 50.f);
                ImGui::SliderFloat("Zoom sensitivity", &zoomSensitivity, 0.01f, 50.f);

                ImGui::Separator();

                ImGui::Text("Camera rotation angles");
                float theta = camera.getTheta(), phi = camera.getPhi();
                ImGui::SliderFloat("Theta", &theta, 0, M_PI);
                ImGui::SliderFloat("Phi", &phi, 0, 2 * M_PI);
                camera.setTheta(theta);
                camera.setPhi(phi);

                ImGui::Separator();

                if (ImGui::Button("Reset camera")) {
                    camera.setTheta(M_PI / 4); 
                    camera.setPhi(M_PI / 1.5);
                    camera.setRadius(5.5f);
                    camera.setCenter(glm::vec3(0, 0, 0));
                    camera.setUp(glm::vec3(0, 1, 0));
                    sensitivity = 1.5f;
                    panSensitivity = 1.0f;
                    zoomSensitivity = 1.0f;
                }

                ImGui::End();
            }
            // Render window
            static bool windowFocus = false;
            { 
                ImGui::Begin("Renderer", &p_open, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);       
                ImGui::Image((void*)(intptr_t)textureRenderer.getTexture(), ImGui::GetWindowSize());   // Render texture
                windowFocus = ImGui::IsWindowFocused() || ImGui::IsWindowHovered();
                ImGui::End();
            }

            // Mouse events
            ImVec2 size = ImGui::GetWindowSize();
            ImVec2 mousePositionAbsolute = ImGui::GetMousePos();
            ImVec2 screenPositionAbsolute = ImGui::GetItemRectMin();
            ImVec2 mousePositionRelative = ImVec2(mousePositionAbsolute.x - screenPositionAbsolute.x, mousePositionAbsolute.y - screenPositionAbsolute.y);

            static bool first = true;
            static ImVec2 previous(0, 0);

            if(ImGui::IsMouseDown(ImGuiMouseButton_Left) || ImGui::IsMouseDown(ImGuiMouseButton_Right)) {
                if(first) {
                    previous = mousePositionRelative;
                    first = false;
                }
            }else first = true;

            // Camera rotation
            if(ImGui::IsMouseDragging(ImGuiMouseButton_Left) && windowFocus) {
                float dTheta = (mousePositionRelative.x - previous.x) / size.x;
                float dPhi = (mousePositionRelative.y - previous.y) / size.y;
                previous = mousePositionRelative;
                camera.rotate(-dTheta * sensitivity, dPhi * sensitivity);
            }

            // Camera pan
            if(ImGui::IsMouseDragging(ImGuiMouseButton_Right) && windowFocus) {
                float dx = (mousePositionRelative.x - previous.x) / (size.x / 2);
                float dy = (mousePositionRelative.y - previous.y) / (size.y / 2);
                previous = mousePositionRelative;
                camera.pan(dx * panSensitivity, -dy * panSensitivity);
            }

            // Camera zoom
            if(windowFocus) camera.zoom(ImGui::GetIO().MouseWheel * zoomSensitivity);
            
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
    else dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;


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
            if (ImGui::MenuItem("Close", NULL, false, p_open != NULL)) exit(0);
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::End();
}

void resizeFun(GLFWwindow* window, int width, int height) {
    textureRenderer.updateViewPort(width, height);
}