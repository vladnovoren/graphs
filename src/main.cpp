#include "app.h"


int main() {
  App app = {};
  int err_code = App_Init(&app);
  err_code = App_Exec(&app);
  if (err_code)
    return err_code;
  err_code = App_Deinit(&app);
  if (err_code)
    return err_code;

  return 0;
}

/*
  SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);

  SDL_Window* window = SDL_CreateWindow("Window name", 
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        1280,
                                        720,
                                        SDL_WINDOW_RESIZABLE);

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_Texture* back_texture = SDL_CreateTexture(renderer,
                                                SDL_PIXELFORMAT_RGBA8888,
                                                SDL_TEXTUREACCESS_TARGET,
                                                800,
                                                600);

  SDL_Texture* front_texture = SDL_CreateTexture(renderer,
                                                 SDL_PIXELFORMAT_RGBA8888,
                                                 SDL_TEXTUREACCESS_TARGET,
                                                 200,
                                                 100);

  SDL_Texture* common_texture = SDL_CreateTexture(renderer, 
                                                  SDL_PIXELFORMAT_RGBA8888,
                                                  SDL_TEXTUREACCESS_TARGET,
                                                  800,
                                                  600);

  Circle circle   = {
    640,
    360,
    100,
    true
  };

  SDL_Event event;

  SDL_Rect front_rect = {
    0,
    0,
    200,
    100
  };

  SDL_Rect back_rect = {
    0,
    0,
    800,
    600
  };

  SDL_Rect mamacita_rect = {
    0,
    0,
    1280,
    720
  };

  // black mamacita
  SDL_SetRenderTarget(renderer, NULL);
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer);

  // back texture
  SDL_SetRenderTarget(renderer, back_texture);
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);

  SDL_SetRenderTarget(renderer, common_texture);
  SDL_RenderCopy(renderer, back_texture, &back_rect, &back_rect);

  while (1) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
      break;

    time_t prev = SDL_GetTicks();

    // front texture (типа обновили вектор)
    SDL_SetRenderTarget(renderer, front_texture);
    SDL_RenderCopy(renderer, back_texture, &front_rect, &front_rect);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLineF(renderer, 5.5, 5.5, 199.5, 99.5);

    SDL_SetRenderTarget(renderer, common_texture);
    SDL_RenderCopy(renderer, front_texture, &front_rect, &front_rect);

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, common_texture, &back_rect, &back_rect);

    SDL_RenderPresent(renderer);

    SDL_Delay(10);
    time_t cur = SDL_GetTicks();
    printf("FPS: %lf\n",  1000.0f / (cur - prev));
  }


  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
*/