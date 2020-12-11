#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/FreeflyCamera.hpp>

#include <glimac/glm.hpp>

using namespace glimac;



int main(int argc, char** argv) {
  //Initialize SDL and open a window
  SDLWindowManager windowManager(800, 600, "GLImac");

  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  }

  //Load shaders
    FilePath applicationPath(argv[0]);
      Program program = loadProgram(
      applicationPath.dirPath() + "shaders/3D.vs.glsl",
      applicationPath.dirPath() + "shaders/directionallight.fs.glsl"
  );
  program.use();

  //location variables uniformes
  const GLuint idProg = program.getGLId();
  GLint locationMVPMatrix = glGetUniformLocation(idProg, "uMVPMatrix");
  GLint locationMVMatrix = glGetUniformLocation(idProg, "uMVMatrix");
  GLint locationNormal = glGetUniformLocation(idProg, "uNormalMatrix");
  GLint locationKd = glGetUniformLocation(idProg, "uKd");
  GLint locationKs = glGetUniformLocation(idProg, "uKs");
  GLint locationShininess = glGetUniformLocation(idProg, "uShininess");
  GLint locationLightDir_vs = glGetUniformLocation(idProg, "uLightDir_vs");
  GLint locationLightIntensity = glGetUniformLocation(idProg, "uLightIntensity");

  glEnable(GL_DEPTH_TEST);

  glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
  glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
  glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  /*********************************
   * HERE SHOULD COME THE INITIALIZATION CODE
   *********************************/

   //définition de la sphere
   Sphere sphere(1, 32, 16);

   //création de la caméra
   FreeflyCamera camera;


   //Création d'un VBO
   GLuint vbo;
   glGenBuffers(1, &vbo);//1 pour un seul vbo

   // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
   glBindBuffer(GL_ARRAY_BUFFER, vbo);


  glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

  // Debind du VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  //Création du VA0
  GLuint vao;
  glGenVertexArrays(1, &vao);

  //bind du vao
  glBindVertexArray(vao);

  // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
  glBindBuffer(GL_ARRAY_BUFFER, vbo);


  const GLuint VERTEX_ATTR_POSITION = 0;
  const GLuint VERTEX_ATTR_NORMAL = 1;
  const GLuint VERTEX_ATTR_TEXCOORDS = 2;

  //position
  glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
  glVertexAttribPointer(
      VERTEX_ATTR_POSITION,
      3,
      GL_FLOAT,
      GL_FALSE,
      sizeof(ShapeVertex),
      (const GLvoid*) offsetof(ShapeVertex, position)
  );

  //normal
  glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
  glVertexAttribPointer(
      VERTEX_ATTR_NORMAL,
      3,
      GL_FLOAT,
      GL_FALSE,
      sizeof(ShapeVertex),
      (const GLvoid*) offsetof(ShapeVertex, normal)
  );

  //texCoords
  glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);
  glVertexAttribPointer(
      VERTEX_ATTR_TEXCOORDS,
      2,
      GL_FLOAT,
      GL_FALSE,
      sizeof(ShapeVertex),
      (const GLvoid*) offsetof(ShapeVertex, texCoords)
  );



  // Debind du VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Unbind VAO
  glBindVertexArray(0);

  int nbMoon = 32;
  std::vector<glm::vec3> randomAxes;
  for(int i=0; i<nbMoon; i++){
    randomAxes.push_back(glm::sphericalRand(2.f));
  }

  GLfloat shininess = 0.8;

  // Application loop:
  bool done = false;
  while(!done) {
      // Event loop:
      SDL_Event e;
      while(windowManager.pollEvent(e)) {
          if(e.type == SDL_QUIT) {
              done = true; // Leave the loop after this iteration
        }
      if(windowManager.isKeyPressed(SDLK_z))camera.moveFront(0.1);
      if(windowManager.isKeyPressed(SDLK_s))camera.moveFront(-0.1);
      if(windowManager.isKeyPressed(SDLK_q))camera.moveLeft(0.1);
      if(windowManager.isKeyPressed(SDLK_d))camera.moveLeft(-0.1);

      if(windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)){
        //Ici on récupère les positions de la souris
        glm::vec2 mousePos = windowManager.getMousePosition();
        float mousePosX = mousePos.x/800.0f - 0.5;
        float mousePosY = mousePos.y/600.0f - 0.5;

        camera.rotateLeft(-2*mousePosX);
        camera.rotateUp(-2*mousePosY);
        std::cout<<"hola"<<std::endl;
        }
      }

    glm::mat4 ViewMatrix = camera.getViewMatrix();

    ProjMatrix =  glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
    MVMatrix = ViewMatrix * glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glBindVertexArray(vao);

      glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
      MVMatrix = ViewMatrix * glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0,1,0));
      glUniformMatrix4fv(
        locationMVPMatrix,
        1,
        GL_FALSE,
        glm::value_ptr(ProjMatrix * MVMatrix));

      glUniformMatrix4fv(
          locationMVMatrix,
          1,
          GL_FALSE,
          glm::value_ptr(MVMatrix));

        glUniformMatrix4fv(
            locationNormal,
            1,
            GL_FALSE,
            glm::value_ptr(NormalMatrix));

        glUniform3fv(locationKd, 1, glm::value_ptr(glm::vec3(0.9,0.5,0.9)));
        glUniform3fv(locationKs, 1, glm::value_ptr(glm::vec3(0.9,0.6,0.6)));
        glUniform1f(locationShininess, 2.);
        glm::vec4 direction = ViewMatrix * glm::vec4(1.,1.,1.,0.);
        glUniform3fv(locationLightDir_vs, 1, glm::value_ptr(direction));
        glUniform3fv(locationLightIntensity, 1, glm::value_ptr(glm::vec3(1.,1.,1.)));


            // Drawing call
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());


            for(int i=0; i<nbMoon; i++){
              glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
              MVMatrix = glm::rotate(MVMatrix, windowManager.getTime() * 1/4, glm::vec3(0,1,0));
              MVMatrix = glm::translate(MVMatrix, randomAxes[i]);
              MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2));

              glUniformMatrix4fv(
                locationMVPMatrix,
                1,
                GL_FALSE,
                glm::value_ptr(ProjMatrix * MVMatrix));

                glUniformMatrix4fv(
                  locationMVMatrix,
                  1,
                  GL_FALSE,
                  glm::value_ptr(MVMatrix));

                  glUniformMatrix4fv(
                    locationNormal,
                    1,
                    GL_FALSE,
                    glm::value_ptr(NormalMatrix));
              // Drawing call
              glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
            }

            glBindVertexArray(0);

      // Update the display
      windowManager.swapBuffers();
  }

  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);

  return EXIT_SUCCESS;
}
