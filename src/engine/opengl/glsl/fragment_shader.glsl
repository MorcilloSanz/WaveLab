#version 330 core

out vec4 FragColor;  

in vec3 ourColor;
in vec3 Normal;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform bool hasTexture; 
  
void main() {
    FragColor = vec4(ourColor, 1.0);
    if(hasTexture) {
        FragColor = vec4(ourColor, 1.0) * texture(ourTexture, TexCoord);
    }
}