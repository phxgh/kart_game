#include "texture_manager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
    for (auto texture : mTextures)
        SDL_DestroyTexture(texture);
}

void TextureManager::LoadAllTextures(SDL_Renderer *pRenderer)
{
    namespace fs = std::filesystem;
    int i = 0;
    for (const auto &entry : fs::directory_iterator("assets/textures"))
    {
        if (!(entry.is_regular_file() && entry.path().extension() == ".png"))
            return;
        mTextures[i] = IMG_LoadTexture(pRenderer, entry.path().c_str());
        i++;
    }
}

SDL_Texture *TextureManager::GetTexture(TextureHandle pHandle)
{
    return mTextures[pHandle];
}
