#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/Sphere.hpp>

#include <glimac/glm.hpp>


using namespace glimac;

GLint uEarthTexture = 0;
GLint uCloudTexture = 0;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Load images
    std::unique_ptr<Image> image = loadImage("/home/erwi/Documents/GLImac-Template/TP3/assets/EarthMap.jpg");
    std::unique_ptr<Image> imageMoon = loadImage("/home/erwi/Documents/GLImac-Template/TP3/assets/MoonMap.jpg");
    std::unique_ptr<Image> imageCloud = loadImage("/home/erwi/Documents/GLImac-Template/TP3/assets/CloudMap.jpg");
    if(image==NULL && imageMoon==NULL && imageCloud==NULL){
      std::cout<<"erreur de chargement"<<std::endl;
    }
    else{
      std::cout<<"Images chargées"<<std::endl;
    }


    GLuint textureEarth;
    GLuint textureMoon;
    GLuint textureCloud;

    //texture terre
    glGenTextures(1, &textureEarth);
    glBindTexture(GL_TEXTURE_2D, textureEarth);
    //level et border à 0
    glTexImage2D(
      GL_TEXTURE_2D,
  	  0,
  	  GL_RGBA,
  	  image->getWidth(),
  	  image->getHeight(),
  	  0,
      GL_RGBA,
  	  GL_FLOAT,
  	  image->getPixels());

    //filtres
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Debind texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //texture Lune
    glGenTextures(1, &textureMoon);
    glBindTexture(GL_TEXTURE_2D, textureMoon);
    //level et border à 0
    glTexImage2D(
      GL_TEXTURE_2D,
  	  0,
  	  GL_RGBA,
  	  imageMoon->getWidth(),
  	  imageMoon->getHeight(),
  	  0,
      GL_RGBA,
  	  GL_FLOAT,
  	  imageMoon->getPixels());

    //filtres
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Debind texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //texture Cloud
    glGenTextures(1, &textureCloud);
    glBindTexture(GL_TEXTURE_2D, textureCloud);
    //level et border à 0
    glTexImage2D(
      GL_TEXTURE_2D,
  	  0,
  	  GL_RGBA,
  	  imageCloud->getWidth(),
  	  imageCloud->getHeight(),
  	  0,
      GL_RGBA,
  	  GL_FLOAT,
  	  imageCloud->getPixels());

    //filtres
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Debind texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //Load shaders
      FilePath applicationPath(argv[0]);
        Program program = loadProgram(
        applicationPath.dirPath() + "shaders/3D.vs.glsl",
        applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl"
    );
    program.use();

    //location variables uniformes
    const GLuint idProg = program.getGLId();
    GLint locationMVPMatrix = glGetUniformLocation(idProg, "uMVPMatrix");
    GLint locationMVMatrix = glGetUniformLocation(idProg, "uMVMatrix");
    GLint locationNormal = glGetUniformLocation(idProg, "uNormalMatrix");
    // Récupère la location de la première texture dans le shader
    GLint uEarthTexture = glGetUniformLocation(idProg, "uEarthTexture");
    // Récupère la location de deuxieme texture dans le shader
    GLint uCloudTexture = glGetUniformLocation(idProg, "uCloudTexture");
    // Indique à OpenGL qu'il doit aller chercher sur l'unité de texture 0
    // pour lire dans la texture uEarthTexture:
    glUniform1i(uEarthTexture, 0);
    // Indique à OpenGL qu'il doit aller chercher sur l'unité de texture 1
    // pour lire dans la texture uEarthTexture:
    glUniform1i(uCloudTexture, 1);

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

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vao);
        glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
        MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0,1,0));
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

              glActiveTexture(GL_TEXTURE0);
              uEarthTexture = textureEarth;
              uCloudTexture = textureCloud;
              glBindTexture(GL_TEXTURE_2D, uEarthTexture);
              glActiveTexture(GL_TEXTURE1);
              glBindTexture(GL_TEXTURE_2D, uCloudTexture);
              uEarthTexture = 0;
              uCloudTexture = 0;

              // Drawing call
              glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

              glActiveTexture(GL_TEXTURE0);
              glBindTexture(GL_TEXTURE_2D, 0); // débind sur l'unité GL_TEXTURE0
              glActiveTexture(GL_TEXTURE1);
              glBindTexture(GL_TEXTURE_2D, 0); // débind sur l'unité GL_TEXTURE1


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

                      glActiveTexture(GL_TEXTURE0);
                      uEarthTexture = textureMoon;
                      glBindTexture(GL_TEXTURE_2D, uEarthTexture);
                      uEarthTexture = 0;
                // Drawing call
                glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
              }

              glActiveTexture(GL_TEXTURE0);
              glBindTexture(GL_TEXTURE_2D, 0); // débind sur l'unité GL_TEXTURE0
              glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteTextures(1,&textureEarth);
    glDeleteTextures(1,&textureMoon);
    glDeleteTextures(1,&textureCloud);

    return EXIT_SUCCESS;
}
