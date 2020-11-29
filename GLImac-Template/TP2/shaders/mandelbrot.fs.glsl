#version 300 es

precision mediump float;

in vec3 vColor;
in vec2 vPosition;

out vec3 fFragColor;

vec2 complexSqr(vec2 z){
  return vec2( ((z.x*z.x) - (z.y*z.y)) , (2.0*z.x*z.y) );
}

void main() {

    vec2 z0 = vPosition;
    vec2 c = vec2(0.0, 0.0);
    float Nmax = 50.0;

    for(float n = 0.0; n<Nmax; n++){
      vec2 zn = complexSqr(c) + z0;
      if(sqrt((zn.x*zn.x) + (zn.y*zn.y)) <= 2.0){
        fFragColor = vec3(0.0,0.0,0.0);
      }else{
        fFragColor = vColor;
      }
      c = zn;
    }

}
