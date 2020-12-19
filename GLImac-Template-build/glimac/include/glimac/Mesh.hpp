#pragma once
#include <glimac/glm.hpp>
#include <iostream>
#include <vector>
#include "Vertex.hpp"
#include "Texture.hpp"
#include "Program.hpp"

class Mesh {
       public:
        std::vector<Vertex> vertices; //Vecteur des vertex
        std::vector<unsigned int> indices; //indices du vertex
        std::vector<Texture> textures; //vecteur pour les textures (coordonnees)
        GLuint VAO, VBO, EBO;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures){
          this->vertices = vertices;
          this->indices = indices;
          this->textures = textures;
          setupMesh();
        };

        void setupMesh();

        void Draw(glimac::Program &shader);

};
