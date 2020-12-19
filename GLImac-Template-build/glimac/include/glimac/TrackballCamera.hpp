#pragma once
#include <glimac/glm.hpp>

class TrackballCamera
{
  public:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;

  public:
    TrackballCamera(){
      m_fDistance = 5.f;
      m_fAngleX = 0.f;
      m_fAngleY = 0.f;
    };

  void moveFront(float delta);
  void rotateLeft(float degrees);
  void rotateUp(float degrees);
  glm::mat4 getViewMatrix() const;
};
