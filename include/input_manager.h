#pragma once

#include <SDL3/SDL.h>

class InputManager
{
public:
public:
    void Init();
    void Input(SDL_Event pEvent);

    int GetHorizontal();
    int GetVertical();

    bool GetDrift();
    bool GetUse();
private:
    bool mDrift, mUse;
    const bool *mKeys;
};
