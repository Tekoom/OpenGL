#version 300 es
precision mediump float;

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTexture;

out vec2 vVertexTexture;

uniform mat3 uModelMatrix;

void main(){
  vVertexTexture = aVertexTexture;
  vec2 transformed = (uModelMatrix * vec3(aVertexPosition, 1)).xy;
  gl_Position = vec4(transformed, 0, 1);
};
