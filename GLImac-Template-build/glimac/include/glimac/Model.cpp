#include "glimac/Model.hpp"

using namespace std;

void Model::DrawModel(glimac::Program &shader)
{
    for(unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].Draw(shader);
}

void Model::loadModel(std::string path)
{
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
       if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
        return;
    }
    std::cout<<"error avant process node"<<std::endl;
    directory = path.substr(0, path.find_last_of('/'));
    processNode(scene->mRootNode, scene);
    std::cout<<"error après process node"<<std::endl;
}


void Model::processNode(aiNode *node, const aiScene *scene)
{
    // traitement de toutes les mailles du nœud
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
     }
    // effectuer la même opération pour chaque nœud fils
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        // traitement des positions
        glm::vec3 vPos;
        vPos.x = mesh->mVertices[i].x;
        vPos.y = mesh->mVertices[i].y;
        vPos.z = mesh->mVertices[i].z;
        vertex.Position = vPos;
        std::cout<<"Position : "<<std::endl;
        std::cout<<vertex.Position<<std::endl;

        //traitement des normales et coordonnées de textures des sommets
        if(mesh->HasNormals())
        {
          glm::vec3 vNormal;
          vNormal.x = mesh->mNormals[i].x;
          vNormal.y = mesh->mNormals[i].y;
          vNormal.z = mesh->mNormals[i].z;
          vertex.Normal = vNormal;
          std::cout<<"Normal : "<<std::endl;
          std::cout<<vertex.Normal<<std::endl;
        }

        //traitement des coordonnées de textures des sommets
        if(mesh->mTextureCoords[0]) // y a-t-il des coordonnées de textures ?
        {
          glm::vec2 tex;
          tex.x = mesh->mTextureCoords[0][i].x;
          tex.y = mesh->mTextureCoords[0][i].y;
          vertex.TexCoords = tex;
          std::cout<<"tex : "<<std::endl;
          std::cout<<vertex.TexCoords<<std::endl;
        }
        else
        {
          vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }
        vertices.push_back(vertex);
    }

    // Traitement des indices
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
  {
      aiFace face = mesh->mFaces[i];
      for(unsigned int j = 0; j < face.mNumIndices; j++)
          indices.push_back(face.mIndices[j]);
  }

    // Traitement des matériaux
    if(mesh->mMaterialIndex >= 0)
    {
      aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];

      std::vector<Texture> diffuseMaps = loadMaterialTextures(material,
        aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }

    return Mesh(vertices, indices, textures);
}


GLuint TextureFromFile(const char *path, const std::string &directory){
  std::string filename = std::string(path);
  filename = directory + '/' + filename;
  glimac::FilePath filepath(filename);

  std::unique_ptr<glimac::Image> image = loadImage(filepath);
  if(image==NULL){
    std::cerr<<"error: image" << filename << "could not be loaded" << std::endl;
    return EXIT_FAILURE;
  }

  GLuint tex;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getWidth(), image->getHeight(), 0, GL_RGBA, GL_FLOAT, image->getPixels());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glBindTexture(GL_TEXTURE_2D,0);

  return tex;
}


std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
{
    std::vector<Texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for(unsigned int j = 0; j < textures_loaded.size(); j++)
        {
            if(std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
            {
                textures.push_back(textures_loaded[j]);
                skip = true;
                break;
            }
        }
        if(!skip)
        {   // si la texture n’a pas été déjà chargée, on le fait
            Texture texture;
            texture.id = TextureFromFile(str.C_Str(), directory);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            textures_loaded.push_back(texture); // ajouter aux textures connues
        }
    }
    return textures;
}
