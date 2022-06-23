#include "Window.h"

int Window::CallbackManager::width = 0;
int Window::CallbackManager::height = 0;
std::function<void(GLFWwindow*, double, double)> Window::CallbackManager::mouseFun = nullptr;
std::function<void(GLFWwindow*, int, int)> Window::CallbackManager::resizeFun = nullptr;
std::function<void(GLFWwindow*, int, int, int)> Window::CallbackManager::mouseButtonFun = nullptr;

Window::Window(const std::string& _title, unsigned int _width, unsigned int _height) 
    : title(_title) {
    CallbackManager::width = _width;
    CallbackManager::height = _height;
    initWindow();
}

void Window::initGlew() {
    if (glewInit() != GLEW_OK) {
        std::cout << "Couldn't initialize GLEW" << std::endl;
        return;
    }
}

void Window::initWindow() {
    // Init window
    if (!glfwInit()) {
        std::cout << "Couldn't initialize window" << std::endl;
        return;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    window = glfwCreateWindow(CallbackManager::width, CallbackManager::height, title.c_str(), NULL, NULL);
    if (!window) terminate();
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, CallbackManager::frameBufferSizeCallback);
    glfwSetCursorPosCallback(window, CallbackManager::mouseCallback);
    glfwSetMouseButtonCallback(window, CallbackManager::mouseButtonCallback);
    glfwSwapInterval(1);
    // Init glew
    initGlew();
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::CallbackManager::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    CallbackManager::width = width;
    CallbackManager::height = height;
    if(resizeFun != nullptr) resizeFun(window, width, height);
}

void Window::CallbackManager::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    if(mouseFun != nullptr) mouseFun(window, xpos, ypos);
}

void Window::CallbackManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if(mouseButtonFun != nullptr) mouseButtonFun(window, button, action, mods);
}