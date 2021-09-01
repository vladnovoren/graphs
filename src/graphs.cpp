#include "graphs.h"


int GetSdlErr() {
  fprintf(stderr, "%s\n", SDL_GetError());
  return 1;
}


int Graph_Create(Graph* graph, SDL_Renderer* renderer, uint32_t format, int access, int w, int h) {
  assert(graph);

  
}


int Graph_Destruct(Graph* graph) {
  assert(graph);
}

