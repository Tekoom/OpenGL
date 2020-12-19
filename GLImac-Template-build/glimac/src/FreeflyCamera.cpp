#include "glimac/FreeflyCamera.hpp"

void FreeflyCamera::moveLeft(float t){
  m_Position += t*m_LeftVector;
  computeDirectionVectors();
}

void FreeflyCamera::moveFront(float t){
  m_Position += t*m_FrontVector;
  computeDirectionVectors();
}

void FreeflyCamera::rotateLeft(float degrees){
  m_fPhi += glm::radians(degrees);
  computeDirectionVectors();
}

void FreeflyCamera::rotateUp(float degrees){
  m_fTheta += glm::radians(degrees);
  computeDirectionVectors();
}


glm::mat4 FreeflyCamera::getViewMatrix() const{
  //Arg1 : Position, arg2 :: Point que la caméra regarde (Pos + VectF), arg3:: l'axe de la caméra (VecU)
  glm::mat4 ViewMatrix = glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
  return ViewMatrix;
}
