#include "graph.h"



// Coords
int CoordSys_Init(CoordSys* coord_sys, SDL_Renderer* renderer, const SDL_Rect rect, const Ranges ranges) {
  assert(renderer);
  assert(coord_sys);

  coord_sys->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
  if (!coord_sys->texture)
    return GetSdlErr();

  coord_sys->rect = {
    rect.x,
    rect.y,
    rect.w,
    rect.h
  };

  coord_sys->ranges = {
    ranges.min_x,
    ranges.max_x,
    ranges.min_y,
    ranges.max_y
  };

  coord_sys->dx = (float)rect.w / (ranges.max_x - ranges.min_x);
  coord_sys->dy = (float)rect.h / (ranges.max_y - ranges.min_y);

  coord_sys->center_x = coord_sys->dx * abs(ranges.min_x);
  coord_sys->center_y = coord_sys->dy * abs(ranges.max_y);

  return 0;
}


float PrettyFunction(float x) {
  return x * sin(x);
}


float CoordSys_RealToPixelX(CoordSys* coord_sys, float x) {
  assert(coord_sys);

  return (x - coord_sys->ranges.min_x) * coord_sys->dx;
}


float CoordSys_RealToPixelY(CoordSys* coord_sys, float y) {
  assert(coord_sys);

  return (coord_sys->ranges.max_y - y) * coord_sys->dy;
}


int CoordSys_PlotFunc(CoordSys* coord_sys, SDL_Renderer* renderer) {
  assert(coord_sys);
  assert(renderer);

  int err_code = 0;

  float step = 1 / coord_sys->dx;

  float prev_y = 0,
        cur_y  = PrettyFunction(coord_sys->ranges.min_x);

  for (float x = coord_sys->ranges.min_x + step; x < coord_sys->ranges.max_x; x += step) {
    prev_y = cur_y;
    cur_y = PrettyFunction(x);
    err_code = SDL_RenderDrawLineF(renderer, CoordSys_RealToPixelX(coord_sys, x - step), CoordSys_RealToPixelY(coord_sys, prev_y),
                                             CoordSys_RealToPixelX(coord_sys, x), CoordSys_RealToPixelY(coord_sys, cur_y));
    if (err_code)
      return GetSdlErr(err_code);
  }

  return 0;
}


int CoordSys_Render(CoordSys* coord_sys, SDL_Renderer* renderer) {
  assert(coord_sys);
  assert(renderer);

  int err_code = 0;
  err_code = SDL_SetRenderTarget(renderer, coord_sys->texture);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_RenderClear(renderer);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  if (err_code)
    return GetSdlErr(err_code);

  if (coord_sys->ranges.min_x < 0 && 0 < coord_sys->ranges.max_x) {
    err_code = Vector_Render(renderer, {coord_sys->center_x, (float)coord_sys->rect.h, 0, (float)-coord_sys->rect.h}, false);
    if (err_code)
      return GetSdlErr(err_code);
  }

  if (coord_sys->ranges.min_y < 0 && 0 < coord_sys->ranges.max_y) {
    err_code = Vector_Render(renderer, {0, coord_sys->center_y, (float)coord_sys->rect.w, 0}, false);
    if (err_code)
      return GetSdlErr(err_code);
  }

  err_code = SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  if (err_code)
    return GetSdlErr(err_code);

  return CoordSys_PlotFunc(coord_sys, renderer);
}


void CoordSys_Destruct(CoordSys* coord_sys) {
  assert(coord_sys);

  SDL_DestroyTexture(coord_sys->texture);
  *coord_sys = {};
}


// Graphs
int Graph_Init(Graph* graph, SDL_Renderer* renderer, const SDL_Rect rect, const Ranges ranges) {
  assert(renderer);
  assert(graph);

  graph->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
  if (!graph->texture)
    return GetSdlErr();

  graph->rect = {
    rect.x,
    rect.y,
    rect.w,
    rect.h
  };

  int err_code = CoordSys_Init(&graph->coord_sys, renderer, {0, 0, rect.w, rect.h}, ranges);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = CoordSys_Render(&graph->coord_sys, renderer);
  if (err_code)
    return err_code;

  err_code = List_Alloc(&graph->vectors);
  if (err_code)
    return err_code;

  return Graph_RenderCopyCoordSys(graph, renderer);
}


int Graph_RenderCopyCoordSys(Graph* graph, SDL_Renderer* renderer) {
  assert(graph);
  assert(renderer);

  int err_code = SDL_SetRenderTarget(renderer, graph->texture);
  if (err_code)
    return GetSdlErr(err_code);

  return SDL_RenderCopy(renderer, graph->coord_sys.texture, NULL, &graph->coord_sys.rect);
}


int Graph_RenderCopyAllToWindow(Graph* graph, SDL_Renderer* renderer) {
  assert(graph);
  assert(renderer);

  int err_code = SDL_SetRenderTarget(renderer, NULL);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_RenderCopy(renderer, graph->texture, NULL, &graph->rect);
  if (err_code)
    return GetSdlErr(err_code);

  return 0;
}


int Graph_AddVector(Graph* graph, SDL_Renderer* renderer, Vector vector) {
  assert(graph);
  assert(renderer);

  vector.start_x = graph->coord_sys.dx * (vector.start_x - graph->coord_sys.ranges.min_x);
  vector.start_y = graph->coord_sys.dy * (graph->coord_sys.ranges.max_y - vector.start_y);

  vector.proj_x *= graph->coord_sys.dx;
  vector.proj_y *= -graph->coord_sys.dy;

  int err_code = List_PushBack(&graph->vectors, vector);
  if (err_code)
    return err_code;

  err_code = SDL_SetRenderTarget(renderer, graph->texture);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = Vector_Render(renderer, vector);
  if (err_code)
    return err_code;

  return 0;  
}


int Graph_Destruct(Graph* graph) {
  assert(graph);

  SDL_DestroyTexture(graph->texture);
  CoordSys_Destruct(&graph->coord_sys);
  List_Destruct(&graph->vectors);

  return 0;
}
