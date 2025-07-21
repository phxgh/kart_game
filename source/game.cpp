#include "game.h"

Game::Game()
{
    if (!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMEPAD))
    {
        printf("Failed to initialize SDL3, error: %s\n", SDL_GetError());
        return;
    }

    mWindow = SDL_CreateWindow(Config::WINDOW_TITLE.c_str(), Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, 0);
    if (mWindow == nullptr)
    {
        printf("Failed to create window, error: %s\n", SDL_GetError());
        return;
    }

    mRenderer = SDL_CreateRenderer(mWindow, nullptr);
    if (mRenderer == nullptr)
    {
        printf("Failed to create window, error: %s\n", SDL_GetError());
        return;
    }

    mLastTime = SDL_GetTicks();

    mTextureManager.LoadAllTextures(mRenderer);

    mRunning = true;
}

Game::~Game()
{
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);

    SDL_Quit();
}

void Game::Run()
{
    while (mRunning)
    {
        Input();
        Update();
        Render();
    }
}

void Game::Input()
{
    for (SDL_Event event; SDL_PollEvent(&event);)
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                mRunning = false;
            break;
        }
    }
}

void Game::Update()
{
    mCurrentTime = SDL_GetTicks();
    mDt = (mCurrentTime - mLastTime) / Config::DELTA_DIVIDEND;

    mLastTime = mCurrentTime;
}

void Game::Render()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(mRenderer);

    SDL_RenderPresent(mRenderer);
}
