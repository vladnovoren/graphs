#include "graph.h"


int GetSdlErr() {
  fprintf(stderr, "%s\n", SDL_GetError());
  return 1;
}


int DrawGraph(SDL_Renderer* renderer, const Graph* graph) {
  assert(graph);

  if (SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 1))
    return GetSdlErr();

  if (SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xff, 0x00))
    return GetSdlErr();

  return 0;
}
