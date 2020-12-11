#version 300 es
precision mediump float;


// Sorties du shader
in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View

out vec3 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong(){
  float d = distance(vPosition_vs, uLightPos_vs);
  return (uLightIntensity*(uKd*(dot(normalize(uLightPos_vs - vPosition_vs),vNormal_vs))+uKs*(pow(dot((normalize(uLightPos_vs - vPosition_vs)+normalize(uLightPos_vs))/2., vNormal_vs),uShininess))))/(d*d);
}

void main() {
  fFragColor = blinnPhong();
}
