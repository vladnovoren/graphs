#include "plotter.h"


Plotter::Plotter(SDL_Renderer* renderer, const SDL_Rect& location, const Ranges& ranges) {
  assert(renderer);

  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, location.w, location.h);

  this->renderer = renderer;
  this->location = location;
  this->ranges = ranges;

  dx = double(location.w / (ranges.max_x - ranges.min_x));
  dy = double(location.h / (ranges.max_y - ranges.min_y));

  center_px = abs(ranges.min_x) * dx;
  center_py = abs(ranges.max_y) * dy;
}


double Plotter::RealToPixelX(double x) {
  return center_px + x * dx;
}


double Plotter::RealToPixelY(double y) {
  return center_py - y * dy;
}


void Plotter::RenderVector(const Vector& v, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool arrow) {
  double begin_x = v.GetBeginX();
  double begin_y = v.GetBeginY();
  double end_x = begin_x + v.GetProjX();
  double end_y = begin_y + v.GetProjY();

  SDL_SetRenderTarget(renderer, texture);
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  lineRGBA(renderer, RealToPixelX(begin_x), RealToPixelY(begin_y), RealToPixelX(end_x), RealToPixelY(end_y), r, g, b, a);
  if (arrow && v.GetProjX() && v.GetProjY())
    printf("vector begin: %lf %lf\n", RealToPixelX(begin_x), RealToPixelY(begin_y));

  // if (arrow) {
  //   Vector center = v;
  //   center.CounterDirect();
  //   center.ChangeLength(VECTOR_ARROW_P_PROJ / dx);
  
  //   Vector right_wing = center;
  //   right_wing.RotateLeft();
  //   right_wing.NumberMul(VECTOR_ARROW_MUL);

  //   Vector left_wing = center;
  //   left_wing.RotateRight();
  //   left_wing.NumberMul(VECTOR_ARROW_MUL);

  //   right_wing.Add(center);
  //   left_wing.Add(center);

  //   RenderVector(left_wing, r, g, b, a, false);
  //   RenderVector(right_wing, r, g, b, a, false);
  // }
}


void Plotter::RenderBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  Vector axis_x(ranges.min_x, 0, ranges.max_x - ranges.min_x, 0);
  Vector axis_y(0, ranges.min_y, 0, ranges.max_y - ranges.min_y);

  SDL_SetRenderTarget(renderer, texture);
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  RenderVector(axis_x, 0x00, 0x00, 0x00, 0xFF);
  RenderVector(axis_y, 0x00, 0x00, 0x00, 0xFF);
}


void Plotter::Present() {
  SDL_SetRenderTarget(renderer, NULL);
  SDL_RenderCopy(renderer, texture, NULL, &location);
  SDL_RenderPresent(renderer);
}


Plotter::~Plotter() {
  SDL_DestroyTexture(texture);
};
