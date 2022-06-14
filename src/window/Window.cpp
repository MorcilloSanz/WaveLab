#include "Window.h"

Window::Window(const std::string& _title, unsigned int _width, unsigned int _height) 
    : title(_title), width(_width), height(_height) {
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
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window) terminate();
    glfwMakeContextCurrent(window);
    // Init glew
    initGlew();
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}