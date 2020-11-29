#version 300 es
precision mediump float;

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vFragPosition;

mat3 translate(float tx, float ty){
  mat3 Mt = mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));

  return Mt;
}

mat3 scale(float sx, float sy){
  mat3 Ms = mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));

  return Ms;
}

mat3 rotate(float a){
  float radA = radians(a);
  mat3 Mr = mat3(vec3(cos(radA), sin(radA), 0), vec3(-sin(radA), cos(radA), 0), vec3(0, 0, 1));

  return Mr;
}

void main() {
  vFragColor = aVertexColor;
  vFragPosition = aVertexPosition;
  vec2 transformed = (scale(1.5,1.5)*vec3(aVertexPosition, 1)).xy;
  gl_Position = vec4(transformed, 0, 1);
};
