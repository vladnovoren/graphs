#include "app.h"


int App_Init(App* app) {
  assert(app);

  if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO))
    return GetSdlErr();

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

  if (SDL_CreateWindowAndRenderer(APP_WINDOW_WIDTH,
                                  APP_WINDOW_HEIGHT,
                                  SDL_WINDOW_RESIZABLE,
                                  &app->window,
                                  &app->renderer))
    return GetSdlErr();
  
  SDL_SetWindowTitle(app->window, APP_TITLE);

  return 0;
}


int App_ClearBlack(App* app) {
  assert(app);

  int err_code = SDL_SetRenderTarget(app->renderer, NULL);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_SetRenderDrawColor(app->renderer, 0xEE, 0xEE, 0xEE, 0xFF);
  if (err_code)
    return GetSdlErr(err_code);
  
  return SDL_RenderClear(app->renderer);
}


int App_Exec(App* app) {
  assert(app);

  int err_code = Graph_Init(&app->big_graph, app->renderer, {BIG_GRAPH_X, BIG_GRAPH_Y, BIG_GRAPH_WIDTH, BIG_GRAPH_HEIGHT}, {-30, 30, -30, 30});
  if (err_code)
    return GetSdlErr();

  err_code = Graph_Init(&app->lil_graph, app->renderer, {LIL_GRAPH_X, LIL_GRAPH_Y, LIL_GRAPH_WIDTH, LIL_GRAPH_HEIGHT}, {-30, 10, -30, 10});
  if (err_code)
    return GetSdlErr();

  err_code = Graph_AddVector(&app->big_graph, app->renderer, {0, 0, 15, 15});
  if (err_code)
    return err_code;
  
  err_code = Graph_AddVector(&app->lil_graph, app->renderer, {0, 0, -27, -10});
  if (err_code)
    return err_code;

  SDL_Event event = {};
  while (true) {
    time_t prev_t = SDL_GetTicks();
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
      break;

    err_code = App_ClearBlack(app);
    if (err_code)
      return GetSdlErr(err_code);
    
    err_code = Graph_RenderCopyAllToWindow(&app->big_graph, app->renderer);
    if (err_code)
      return err_code;
    
    err_code = Graph_RenderCopyAllToWindow(&app->lil_graph, app->renderer);
    if (err_code)
      return err_code;

    SDL_RenderPresent(app->renderer);
    SDL_Delay(15);
    printf("[FPS]: %lf\n", 1000.0f / (SDL_GetTicks() - prev_t));
  }

  return 0;
}


int App_Deinit(App* app) {
  assert(app);

  SDL_DestroyWindow(app->window);
  SDL_DestroyRenderer(app->renderer);

  Graph_Destruct(&app->lil_graph);
  Graph_Destruct(&app->big_graph);
  SDL_Quit();

  return 0;
}
