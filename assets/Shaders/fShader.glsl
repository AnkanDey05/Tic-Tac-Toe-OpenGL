#version 330 core

in vec2 vUV;
out vec4 FragColor;

uniform sampler2D u_Texture;
uniform vec4 u_Color;
uniform bool u_UseTexture;

void main()
{
    vec4 texColor = u_UseTexture
        ? texture(u_Texture, vUV)
        : vec4(1.0);

    FragColor = texColor * u_Color;
}
