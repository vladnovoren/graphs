#include "geometry.h"


int Circle_Render(SDL_Renderer* renderer, const Circle circle) {
  assert(renderer);

  int err_code = 0;

  double old_x = -circle.radius,
         old_y = 0,
         cur_x = old_x + 1,
         cur_y = 0;

  float sqr_radius = pow(circle.radius, 2);
  for (; cur_x <= circle.radius; ++cur_x) {
    cur_y = sqrt(sqr_radius - cur_x * cur_x);

    err_code = SDL_RenderDrawLineF(renderer, circle.center_x + old_x, circle.center_y + old_y,
                                             circle.center_x + cur_x, circle.center_y + cur_y);
    if (err_code)
      break;

    err_code = SDL_RenderDrawLineF(renderer, circle.center_x + old_x, circle.center_y - old_y,
                                             circle.center_x + cur_x, circle.center_y - cur_y);
    if (err_code)
      break;

    if (circle.is_filled) {
      err_code = SDL_RenderDrawLineF(renderer, circle.center_x + cur_x, circle.center_y + cur_y,
                                               circle.center_x + cur_x, circle.center_y - cur_y);
      if (err_code)
        break;
    }

    old_x = cur_x;
    old_y = cur_y;
  }

  if (err_code)
    return GetSdlErr(err_code);

  return 0;
}


int Vector_Render(SDL_Renderer* renderer, Vector vector, bool dot) {
  assert(renderer);

  float vector_end_x = vector.start_x + vector.proj_x,
        vector_end_y = vector.start_y + vector.proj_y;

  int err_code = SDL_RenderDrawLineF(renderer, vector.start_x, vector.start_y, vector_end_x, vector_end_y);
  if (err_code)
    return GetSdlErr(err_code);

  if (dot) {
    err_code = Circle_Render(renderer, {vector.start_x, vector.start_y, VECTOR_CIRCLE_RADIUS, true});
    if (err_code)
      return err_code;
  }

  float vector_phi = atan2(vector.proj_y, vector.proj_x);
  float first_phi = vector_phi + VECTOR_ARROW_ANGLE;
  float second_phi = vector_phi - VECTOR_ARROW_ANGLE;

  float first_x = vector_end_x - VECTOR_ARRAW_LEN * cos(first_phi);
  float first_y = vector_end_y - VECTOR_ARRAW_LEN * sin(first_phi);

  float second_x = vector_end_x - VECTOR_ARRAW_LEN * cos(second_phi);
  float second_y = vector_end_y - VECTOR_ARRAW_LEN * sin(second_phi);

  err_code = SDL_RenderDrawLineF(renderer, vector_end_x, vector_end_y, first_x, first_y);
  if (err_code)
    return GetSdlErr(err_code);

  err_code = SDL_RenderDrawLineF(renderer, vector_end_x, vector_end_y, second_x, second_y);
  if (err_code)
    return GetSdlErr(err_code);
  
  return 0;
}


bool VectorsEqual(const Vector* a, const Vector* b) {
  return a->start_x == b->start_x &&
         a->start_y == b->start_y &&
         a->proj_x  == b->proj_x  &&
         a->proj_y  == b->proj_y;
}
