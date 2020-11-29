#version 300 es

precision mediump float;

layout(location = 3) in vec2 aVertexPosition;
layout(location = 8) in vec3 aVertexColor;

out vec3 vColor;
out vec2 vPosition;

void main() {
    vColor = aVertexColor;
    vPosition = aVertexPosition;
    gl_Position = vec4(aVertexPosition, 0, 1);
}
