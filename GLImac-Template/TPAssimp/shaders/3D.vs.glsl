#version 300 es
precision mediump float;

// Attributs des sommets
layout(location = 0) in vec3 aVertexPosition; // Position du sommet
layout(location = 1) in vec3 aVertexNormal; // Normale du sommet
layout(location = 2) in vec2 aVertexTexCoords; // Coordonnées de texture du sommet

// Matrices de transformations reçues en uniform
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

// Sorties du shader
out vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
out vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
out vec2 vTexCoords; // Coordonnées de texture du sommet

void main(){
  vec4 position = vec4(aVertexPosition, 1.);
  vec4 normal = vec4(aVertexNormal, 0.);

  vPosition_vs = vec3(uMVMatrix * position);
  vNormal_vs = vec3(uNormalMatrix * normal);
  vTexCoords = aVertexTexCoords;

  gl_Position = uMVPMatrix * position;
}
