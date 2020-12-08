#version 300 es
precision mediump float;

// Sorties du shader
in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

void main() {

  fFragColor = (texture(uEarthTexture, vTexCoords).xyz + texture(uCloudTexture, vTexCoords).xyz);
}
