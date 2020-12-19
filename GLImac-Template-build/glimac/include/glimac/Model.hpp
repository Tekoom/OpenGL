#pragma once
#include <glimac/glm.hpp>
#include <iostream>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Vertex.hpp"
#include "Texture.hpp"
#include "Program.hpp"
#include "Mesh.hpp"
#include "Image.hpp"

class Model{
    public:
      std::vector<Mesh> meshes;
      std::string directory;
      std::vector<Texture> textures_loaded;

        Model(std::string path){
          loadModel(path); //chemin du fichier à charger
        }
        void DrawModel(glimac::Program &shader);
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

GLuint TextureFromFile(const char *path, const std::string &directory);
