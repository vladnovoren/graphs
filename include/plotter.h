#ifndef PLOTTER_H
#define PLOTTER_H

#include <SDL/SDL.h>
#include "geometry.h"

class Plotter {
 private:
  SDL_Renderer* renderer;
  SDL_Texture* texture;

  SDL_Rect location;
  Ranges ranges;

  float dx;
  float dy;
 public:
  explicit Plotter(SDL_Renderer* renderer, const SDL_Rect& location, const Ranges& ranges);



  ~Plotter();
};


#endif /* plotter.h */
