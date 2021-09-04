#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL2/SDL.h>
#include <assert.h>
#include <math.h>
#include "list.h"

struct Circle {
  int  center_x;
  int  center_y;
  int  radius;
  bool is_filled;
};

void RenderDrawCircle(SDL_Renderer* renderer, Circle* circle);


#endif /* geometry.h */
