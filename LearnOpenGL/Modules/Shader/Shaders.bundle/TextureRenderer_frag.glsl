#version 300 es
precision highp float;
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCoord;
uniform sampler2D ourTexture;
void main()
{
    FragColor = texture(ourTexture, TexCoord);
}
