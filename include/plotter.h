#ifndef PLOTTER_H
#define PLOTTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "geometry.h"

const size_t MAX_N_VECTORS = 10;


class Plotter {
 private:
  SDL_Renderer* renderer;
  SDL_Texture* texture;

  SDL_Rect location;
  Ranges ranges;

  double dx;
  double dy;

  double center_px;
  double center_py;
 public:
  explicit Plotter(SDL_Renderer* renderer, const SDL_Rect& location, const Ranges& ranges);

  double RealToPixelX(double x);

  double RealToPixelY(double y);

  void RenderVector(const Vector& v, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool arrow = true);

  void RenderBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  void Present();

  ~Plotter();
};


#endif /* plotter.h */
