#include "Renderer.h"

#include "../../glew/glew.h"

Renderer::Renderer() {
    Shader vertexShader = Shader::fromFile("../src/opengl/glsl/vertex_shader.glsl", Shader::ShaderType::Vertex);
    Shader fragmentShader = Shader::fromFile("../src/opengl/glsl/fragment_shader.glsl", Shader::ShaderType::Fragment);
    shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);
    enableBlending();
    enableAntialiasing();
}

void Renderer::enableBlending() {
    glEnable(GL_BLEND | GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::enableAntialiasing() {
    glEnable(GL_MULTISAMPLE);
}

void Renderer::render() {
    shaderProgram->useProgram();
    for(Group& group : groups) {
        if(group.isVisible()) {
            // Update mvp matrix (get model matrix from group)
            // ......
            // Draw call
            group.draw();
        }
    }
}

void Renderer::clear() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}