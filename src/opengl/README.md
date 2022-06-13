# Graphics engine

Tiny OpenGL graphics engine for drawing 3D graphics

## Basic example

```cpp
// Renderer creates a camera automatically
Renderer renderer;
//renderer.setCamera(Camera::orthoCamera(...));

// Polytopes (Vertices format: x y z r g b)
std::vector<Vec3f> vertices = {
    Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f),
    Vec3f(-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f),
    Vec3f(0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f)
};
Polytope polytope(vertices);

std::vector<Vec3f> vertices2 = {
    Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.2f, 1.0f),
    Vec3f(-0.5f, -0.5f, 0.0f,  1.0f, 0.2f, 1.0f),
    Vec3f(0.0f,  0.5f, 0.0f,  1.0f, 0.2f, 1.0f)
};
Polytope polytope2(vertices2);

// Group
Group group(GL_TRIANGLES);    // OpenGL primitive for drawing
group.add(polytope2);        // Add polytopes to group
group.add(polytope);        // Add polytopes to group

renderer.addGroup(group);   // Add group to renderer
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