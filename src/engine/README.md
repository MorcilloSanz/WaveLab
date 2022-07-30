# Graphics engine

Tiny OpenGL graphics engine for drawing 3D graphics

## Basic example

```cpp
Renderer renderer;  // Renderer creates a camera automatically
//renderer.setCamera(Camera::orthoCamera(...));

// Polytopes (Vertices format: x y z r g b)
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
    . . .
}
```

## Basic drawing

```cpp
while (!window.windowShouldClose()) {

    // Clear
    renderer.clear();

    // Render
    renderer.render();
    
    // Update window
    window.update();
}
```

## Update vertices of a polytope
```cpp
// Update polytope vbo vertices
static float offset = 0.01f;
vertices = {
    Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f),
    Vec3f(-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f),
    Vec3f(0.0f + offset,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f)
};
polytope.updateVertices(vertices);
offset += 0.001;
```

### updateBuffer copy flag
```cpp
void updateVertices(std::vector<Vec3f>& vertices, bool copy2memory = false);
void updateIndices(const std::vector<unsigned int>& indices, bool copy2memory = false);
```
When copy2memory is true, it makes the update slower but it allows you to get it back with the functions *VertexBuffer::getVertices()* and *IndexBuffer::getIndices()*
*warning* compy2memory should always be false

In order to get the data directly from GPU use:
```cpp
inline float* getMapBuffer();           // VertexBuffer::getMapBuffer()
inline unsigned int* getMapBuffer();    // IndexBuffer::getMapBuffer()
```

## Render to a texture
```cpp
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
}
```

This is useful for rendering into an ImGui window like:

```cpp
ImGui::Begin("Renderer");       
ImGui::Image((void*)(intptr_t)textureRenderer.getTexture(), ImGui::GetWindowSize());      
ImGui::End();
```

# Dependencies
GLFW
GLEW
GLM
IMGUI
ASSIMP