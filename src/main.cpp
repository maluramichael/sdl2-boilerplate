#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;

  window = SDL_CreateWindow(
      "SDL2 Boilerplate",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      640,
      480,
      SDL_WINDOW_OPENGL);

  if (window == NULL)
  {
    std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr)
  {
    std::cout << "Could not create a renderer: " << SDL_GetError() << std::endl;
    return 1;
  }

  while (true)
  {
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        break;
      }
    }

    // Clear
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
    SDL_RenderClear(renderer);

    // Draw

    SDL_RenderPresent(renderer);
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
