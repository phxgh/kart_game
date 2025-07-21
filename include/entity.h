#pragma once

#include <glm/glm.hpp>
#include "texture_manager.h"

class Entity
{
public:
    Entity(float pX, float pY, TextureHandle pTextureHandle);
    ~Entity();

    virtual void Update(float &pDt) {}
    virtual void Draw(const SDL_Renderer *&pRenderer) {}
private:
    glm::vec2 mPosition, mVelocity;
    TextureHandle mTextureHandle;
};
