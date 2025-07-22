#pragma once

#include <glm/glm.hpp>
#include "texture_manager.h"

enum class EntityType
{
    Player,
    CPU,
    Box,
    Coin,
};

class Entity
{
public:
    Entity(EntityType pType, float pX, float pY, TextureHandle pTextureHandle);
    ~Entity();

    virtual void Update(float &pDt) {}
    virtual void Draw(const SDL_Renderer *&pRenderer) {}
private:
    glm::vec2 mPosition, mVelocity;
    TextureHandle mTextureHandle;
};
