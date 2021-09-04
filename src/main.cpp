#include "graph.h"
#include "time.h"



int main() {
  SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);

  SDL_Window* window = SDL_CreateWindow("test", 
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        1280,
                                        720,
                                        SDL_WINDOW_RESIZABLE);
  
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");


  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_Texture* texture = SDL_CreateTexture(renderer,
                                           SDL_PIXELFORMAT_RGBA8888,
                                           SDL_TEXTUREACCESS_TARGET,
                                           1280,
                                           720);

  Circle circle   = {
    640,
    360,
    100,
    true
  };

  SDL_Event event;

  while (1) {
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
      break;

    time_t prev = SDL_GetTicks();
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    RenderDrawCircle(renderer, &circle);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopyEx(renderer, texture, NULL, NULL, 15, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
    time_t cur = SDL_GetTicks();
    printf("FPS: %lf\n",  1000.0f / (cur - prev));
  }


  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(texture);
  SDL_Quit();

  return 0;
}
