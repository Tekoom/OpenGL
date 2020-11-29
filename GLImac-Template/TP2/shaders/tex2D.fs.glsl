#version 300 es
precision mediump float;

in vec2 vVertexTexture;

out vec3 fVertexTexture;

uniform vec3 uColor;
uniform sampler2D uTexture;

void main(){
  fVertexTexture = texture(uTexture, vVertexTexture).xyz;
};
