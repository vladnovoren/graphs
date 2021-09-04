#include "geometry.h"


void RenderDrawCircle(SDL_Renderer* renderer, Circle* circle) {
  assert(renderer);
  assert(circle);

  int dx    = 1,
      old_x = -circle->radius,
      old_y = 0,
      cur_x = old_x + dx,
      cur_y = 0;

  float sqr_radius = pow(circle->radius, 2);
  for (; cur_x <= circle->radius; cur_x += dx) {
    cur_y = sqrt(sqr_radius - cur_x * cur_x);
    SDL_RenderDrawLine(renderer, circle->center_x + old_x, circle->center_y + old_y,
                                 circle->center_x + cur_x, circle->center_y + cur_y);
    SDL_RenderDrawLine(renderer, circle->center_x + old_x, circle->center_y - old_y,
                                 circle->center_x + cur_x, circle->center_y - cur_y);
    if (circle->is_filled)
      SDL_RenderDrawLine(renderer, circle->center_x + cur_x, circle->center_y + cur_y,
                                   circle->center_x + cur_x, circle->center_y - cur_y);

    old_x = cur_x;
    old_y = cur_y;
  }
}


bool VectorsEqual(const Vector* a, const Vector* b) {
  return a->start_x == b->start_x &&
         a->start_y == b->start_y &&
         a->proj_x  == b->proj_x  &&
         a->proj_y  == b->proj_y;
}
