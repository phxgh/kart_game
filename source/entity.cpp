#include "entity.h"

Entity::Entity(EntityType pType, float pX, float pY, TextureHandle pTextureHandle):
    mPosition{pX, pY},
    mVelocity{0, 0},
    mTextureHandle(pTextureHandle)
{
}

Entity::~Entity()
{
}
