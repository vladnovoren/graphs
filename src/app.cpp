#include "app.h"


App::App() {
  SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  SDL_CreateWindowAndRenderer(APP_WINDOW_WIDTH,
                              APP_WINDOW_HEIGHT,
                              0,
                              &window,
                              &renderer);
  SDL_SetWindowTitle(window, APP_TITLE);
}


void App::ClearBack() {
  SDL_SetRenderTarget(renderer, NULL);
  SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xEE, 0xFF);
  SDL_RenderClear(renderer);
}


void App::Exec() {
  Plotter lil_plot(renderer, LIL_PLOT_LOCATION, {-10, -10, 10, 10});
  Plotter big_plot(renderer, BIG_PLOT_LOCATION, {-5, -5, 5, 5});

  SDL_Event event = {};
  Vector vector(0, 0, -3, -4);
  time_t diff = 0;
  time_t prev_t = 0;
  while (true) {
    prev_t = SDL_GetTicks();
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
      break;
    ClearBack();
    big_plot.RenderBackground(0xff, 0xff, 0xff, 0xff);
    vector.Rotate(0.05);
    big_plot.RenderVector(vector, 0xff, 0x00, 0x00, 0xff);
    big_plot.Present();
    lil_plot.RenderBackground(0x00, 0xff, 0xff, 0xff);
    lil_plot.Present();
    diff = SDL_GetTicks();
    time_t cur_t = SDL_GetTicks();
    time_t delay = 1000 / 60 - cur_t + prev_t;
    SDL_Delay(delay);
  }
}


App::~App() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  SDL_Quit();
}
