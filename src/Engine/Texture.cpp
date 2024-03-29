#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace myengine;

void Texture::OnLoad()
{
    int w = 0;
    int h = 0;
    unsigned char* data = stbi_load(resourcePath.c_str(), &w, &h, NULL, 4);
    if (!data)
    {
        throw std::exception();
    }

    //create and bind a texture
    glGenTextures(1, &textureID);
    if (!textureID)
    {
        throw std::exception();
    }
    glBindTexture(GL_TEXTURE_2D, textureID);
    //upload the image daya to the bound texture unit in the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //free the loaded data because we now have a copy on the GPU
    free(data);
    //generate mipmap so the texture can be mapped correctly
    glGenerateMipmap(GL_TEXTURE_2D);
    //unbind the texture becase we are done operating on it
    glBindTexture(GL_TEXTURE_2D, 0);
}