#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

#include <glimac/glm.hpp>

using namespace glimac;

class Vertex2DUV
{
    public:

        glm::vec2 position;
        glm::vec2 textureCoordinate;

        Vertex2DUV(){};
        Vertex2DUV(glm::vec2 position, glm::vec2 textureCoordinate)
        {
            this->position = position;
            this->textureCoordinate = textureCoordinate;
        };
};

  float uTime = 45.;


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    // Load shaders
    FilePath applicationPath(argv[0]);
    Program program = loadProgram(
        applicationPath.dirPath() + "shaders/tex2D.vs.glsl",
        applicationPath.dirPath() + "shaders/tex2D.fs.glsl"
    );
    program.use();

    //location variables uniformes
    const GLuint idProg = program.getGLId();
    GLint location = glGetUniformLocation(idProg, "uTime");
    //glGetUniformLocation(idProg, &uTime);
     glUniform1f(location, uTime);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

     //Création d'un VBO
     GLuint vbo;
     glGenBuffers(1, &vbo);//1 pour un seul vbo

     // Binding d'un VBO sur la cible GL_ARRAY_BUFFER:
     glBindBuffer(GL_ARRAY_BUFFER, vbo);

    Vertex2DUV vertices[] = {
      Vertex2DUV(glm::vec2(-0.5, -0.5), glm::vec2(0., 0.)),
      Vertex2DUV(glm::vec2(0.5, -0.5), glm::vec2(0., 0.)),
      Vertex2DUV(glm::vec2(0.5, 0.5), glm::vec2(0., 0.))
    };

    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex2DUV), vertices, GL_STATIC_DRAW);

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
    const GLuint VERTEX_ATTR_UV = 1;

    //position
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(
        VERTEX_ATTR_POSITION,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex2DUV),
        (const GLvoid*) offsetof(Vertex2DUV, position)
    );

    //UV
    glEnableVertexAttribArray(VERTEX_ATTR_UV);
    glVertexAttribPointer(
        VERTEX_ATTR_UV,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex2DUV),
        (const GLvoid*) offsetof(Vertex2DUV, textureCoordinate)
    );

    // Debind du VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind VAO
    glBindVertexArray(0);

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

        glClear(GL_COLOR_BUFFER_BIT);

        // Bind vao
        glBindVertexArray(vao);

        //modification de la valeur utime
        uTime += 0.1;
        glUniform1f(location, uTime);

        // Drawing call
        glDrawArrays(GL_TRIANGLES, 0 /* Because no offset */, 3);

        // Unbind vao
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    return EXIT_SUCCESS;
}
