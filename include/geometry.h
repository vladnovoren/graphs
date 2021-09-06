#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL2/SDL.h>
#include <assert.h>
#include <math.h>
#include "list.h"

const float VECTOR_CIRCLE_RADIUS = 3;
const float VECTOR_ARROW_ANGLE   = 0.523599;
const float VECTOR_ARRAW_LEN = 10;

struct Circle {
  float center_x;
  float center_y;
  float radius;
  bool is_filled;
};

int Circle_Render(SDL_Renderer* renderer, const Circle circle);

int Vector_Render(SDL_Renderer* renderer, Vector vector, bool dot = true);



#endif /* geometry.h */
