#include "Window.h"

int Window::CallbackManager::width = 0;
int Window::CallbackManager::height = 0;
std::function<void(double, double)> Window::CallbackManager::mouseFun = nullptr;
std::function<void(GLFWwindow* window, int width, int height)> Window::CallbackManager::resizeFun = nullptr;

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
    window = glfwCreateWindow(CallbackManager::width, CallbackManager::height, title.c_str(), NULL, NULL);
    if (!window) terminate();
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, CallbackManager::frameBufferSizeCallback);
    glfwSetCursorPosCallback(window, CallbackManager::mouseCallback);
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
    if(mouseFun != nullptr)
        mouseFun(xpos, ypos);
}