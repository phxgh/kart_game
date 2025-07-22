#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include "config.h"
#include "input_manager.h"
#include "texture_manager.h"

class Game
{
public:
    Game();
    ~Game();

    void Run();
private:
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    bool mRunning;

    uint32_t mLastTime, mCurrentTime;
    float mDt;

    TextureManager mTextureManager;
    InputManager mInputManager;
private:
    void Input();
    void Update();
    void Render();
};
