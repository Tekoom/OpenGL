#pragma once

#include <glimac/glm.hpp>

class FreeflyCamera
{
  private:
      glm::vec3 m_Position;
      float m_fPhi;
      float m_fTheta;
      glm::vec3 m_FrontVector;
      glm::vec3 m_LeftVector;
      glm::vec3 m_UpVector;

  public:
      void computeDirectionVectors(){
        m_FrontVector = glm::vec3(glm::cos(m_fTheta)*glm::sin(m_fPhi), glm::sin(m_fTheta), glm::cos(m_fTheta)*glm::cos(m_fPhi));
        m_LeftVector = glm::vec3(glm::sin(m_fPhi + (M_PI/2.)), 0., glm::cos(m_fPhi + (M_PI/2.)));
        m_UpVector = glm::cross(m_FrontVector,m_LeftVector);
      }

      FreeflyCamera(){
        m_Position = glm::vec3(0.,0.,0.);
        m_fPhi = M_PI;
        computeDirectionVectors();
      }

      void moveLeft(float t);
      void moveFront(float t);
      void rotateLeft(float degrees);
      void rotateUp(float degrees);
      glm::mat4 getViewMatrix() const;
};
