#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>

#include "shader.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh {
public:
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;
    glm::vec3 diffuse_color = { 0, 0, 0 };
    glm::vec3 specular_color = { 0, 0, 0 };
    bool uses_material = false;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures,
        glm::vec3 in_diffuse_color = { 0, 0, 0 }, glm::vec3 in_specular_color = { 0, 0, 0 }, bool in_uses = false);
    void Draw(Shader& shader);
private:
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};