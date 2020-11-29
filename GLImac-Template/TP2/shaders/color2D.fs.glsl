#version 300 es
precision mediump float;

in vec3 vFragColor;
in vec2 vFragPosition;

out vec3 fFragColor;

void main() {

  vec2 P = vFragPosition;

    float distance = distance(vec2(0.0, 0.0), P);
    float a = 0.75 * exp(-20.0 * pow(distance, 2.0));

    //float a = length(fract(5.0 * P));
    //float a = length(abs(fract(5.0 * P) * 2.0 - 1.0));
    //float a = mod(floor(10.0 * P.x) + floor(10.0 * P.y), 2.0);
    //float a = smoothstep(0.3, 0.32, length(fract(5.0 * P) - 0.5));
    //float a = smoothstep(0.4, 0.5, max(abs(fract(8.0 * P.x - 0.5 * mod(floor(8.0 * P.y), 2.0)) - 0.5), abs(fract(8.0 * P.y) - 0.5)));

    fFragColor = vFragColor * a;
};
