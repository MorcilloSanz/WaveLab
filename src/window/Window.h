#pragma once

#include <iostream>
#include <string>
#include <functional>

#define GLEW_STATIC
#include "../../glew/glew.h"

#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window;
    unsigned int width, height;
    std::string title;
public:
    Window(const std::string& _title, unsigned int _width, unsigned int _height);
    Window() = default;
    ~Window() = default;
private:
    void initGlew();
    void initWindow();
public:
    void update();

    inline void terminate() {
        glfwTerminate();
    }
public:
    inline GLFWwindow* getGLFWwindow() {
        return window;
    }

    inline bool windowShouldClose() const {
        return glfwWindowShouldClose(window);
    }

    inline unsigned int getWidth() const {
        return width;
    }

    inline unsigned int getHeight() const {
        return height;
    }
};