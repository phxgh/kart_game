#pragma once

#include <array>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <string_view>
#include <filesystem>

enum TextureHandle
{
    
};

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    void LoadAllTextures(SDL_Renderer *pRenderer);
    SDL_Texture *GetTexture(TextureHandle pHandle);
private:
    static const int TextureAmount = 1;
    std::array<SDL_Texture*, TextureAmount> mTextures;
    std::array<std::string_view, TextureAmount> mTexturePaths;
};
