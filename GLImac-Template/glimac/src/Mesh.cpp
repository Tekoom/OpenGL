#include "glimac/Mesh.hpp"

using namespace std;

void Mesh::setupMesh(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    // position des sommets
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
    // normales
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // coordonnées de texture
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    glBindVertexArray(0);
  }

void Mesh::Draw(glimac::Program &shader){
    // unsigned int diffuseNr = 1;
    // unsigned int specularNr = 1;
    //   for(unsigned int i = 0; i < textures.size(); i++)
    //   {
    //     glActiveTexture(GL_TEXTURE0 + i); // Activation de l’unité de texture adéquate avant liaison
    //     // récupère le numéro de la texture (le N dans diffuse_textureN)
    //     std::string number;
    //     std::string name = textures[i].type;
    //     if(name == "texture_diffuse")
    //         number = std::to_string(diffuseNr++);
    //     else if(name == "texture_specular")
    //         number = std::to_string(specularNr++);
    //       glUniform1f(glGetUniformLocation(shader.getGLId(), ("material." + name + number).c_str()), i);
    //       glBindTexture(GL_TEXTURE_2D, textures[i].id);
    //   }
    // glActiveTexture(GL_TEXTURE0);
    // affiche le mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }
