#include "app.h"

int App_Init(App* app) {
  assert(app);

  if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO))
    return GetSdlErr();

  if (SDL_CreateWindowAndRenderer(APP_WIDTH, APP_HEIGHT, APP_WINDOW_FLAGS, &app->window, &app->renderer))
    return GetSdlErr();

  int graph_create_res = Graph_Create(&app->lil_graph);
  if (graph_create_res)
    return GetSdlErr();
  graph_create_res = Graph_Create(&app->big_graph);
  if (graph_create_res)
    return GetSdlErr();

  return 0;
}


int App_Deinit(App* app) {
  assert(app);

  SDL_DestroyWindow(app->window);
  SDL_DestroyRenderer(app->renderer);

  Graph_Destruct(&app->lil_graph);
  Graph_Destruct(&app->big_graph);

  return 0;
}
