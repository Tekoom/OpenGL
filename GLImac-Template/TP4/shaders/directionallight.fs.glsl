#version 300 es
precision mediump float;


// Sorties du shader
in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View

out vec3 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong(){
  return uLightIntensity*(uKd*(dot(normalize(uLightDir_vs),vNormal_vs))+uKs*(pow(dot((normalize(-vPosition_vs)+normalize(uLightDir_vs))/2., vNormal_vs),uShininess)));
}

void main() {
  fFragColor = blinnPhong();
}
