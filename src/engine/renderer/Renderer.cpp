#include "Renderer.h"

#include "../../../glew/glew.h"

Renderer::Renderer() : hasCamera(false) {
    Shader vertexShader = Shader::fromFile("../src/engine/opengl/glsl/vertex_shader.glsl", Shader::ShaderType::Vertex);
    Shader fragmentShader = Shader::fromFile("../src/engine/opengl/glsl/fragment_shader.glsl", Shader::ShaderType::Fragment);
    shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);
    enableBlending();
    enableAntialiasing();
}

void Renderer::enableBlending() {
    glEnable(GL_BLEND & GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::enableAntialiasing() {
    glEnable(GL_MULTISAMPLE);
}

void Renderer::setCamera(Camera& camera) {
    hasCamera = true;
    this->camera = &camera;
}

void Renderer::render() {
    shaderProgram->useProgram();

    glm::mat4 projection(1.f);
    glm::mat4 view(1.f);
    if(hasCamera) {
        projection = camera->getProjectionMatrix();
        view = camera->getViewMatrix();
    }

    for(Group* group : groups) {
        if(group->isVisible()) {
            // Primitive settings
            glPointSize(group->getPointSize());
            glLineWidth(group->getLineWidth());
            // Draw call
            for(Polytope* polytope : group->getPolytopes()) {
                // Calculate model view matrix
                glm::mat4 model = group->getModelMatrix() * polytope->getModelMatrix();
                glm::mat4 mvp = projection * view * model;
                // Send to vertex shader
                shaderProgram->uniformMat4("mvp", mvp);
                // Draw
                polytope->draw(group->getPrimitive(), group->isShowWire());
            }
        }
    }
}

void Renderer::clear() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}