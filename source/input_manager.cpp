#include "input_manager.h"

void InputManager::Init()
{
    mDrift = false;
    mUse = false;
}

void InputManager::Input(SDL_Event pEvent)
{
    mKeys = SDL_GetKeyboardState(NULL);
    switch (pEvent.type)
    {
        case SDL_EVENT_KEY_DOWN:
            mDrift = pEvent.key.mod & SDL_KMOD_SHIFT;
            mUse = pEvent.key.scancode == SDL_SCANCODE_SPACE;

            break;

        case SDL_EVENT_KEY_UP:
            mDrift = pEvent.key.mod & SDL_KMOD_SHIFT;
            mUse = pEvent.key.scancode == SDL_SCANCODE_SPACE;

            break;

        default:
            break;
    }
}

int InputManager::GetHorizontal()
{
    int left = mKeys[SDL_SCANCODE_A] || mKeys[SDL_SCANCODE_LEFT];
    int right = mKeys[SDL_SCANCODE_D] || mKeys[SDL_SCANCODE_RIGHT];

    if (left && !right)
        return -1;
    if (!left && right)
        return 1;
    return 0;
}

int InputManager::GetVertical()
{
    int up = mKeys[SDL_SCANCODE_W] || mKeys[SDL_SCANCODE_UP];
    int down = mKeys[SDL_SCANCODE_S] || mKeys[SDL_SCANCODE_DOWN];

    if (up && !down)
        return -1;
    if (!up && down)
        return 1;
    return 0;
}

bool InputManager::GetDrift()
{
    return mDrift;
}

bool InputManager::GetUse()
{
    return mUse;
}
