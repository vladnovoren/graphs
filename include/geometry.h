#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL2/SDL.h>
#include <cassert>
#include <cmath>

const float VECTOR_CIRCLE_RADIUS = 3;
const float VECTOR_ARROW_ANGLE   = 0.523599;
const float VECTOR_ARRAW_LEN = 10;

struct Ranges {
  float min_x;
  float min_y;

  float max_x;
  float max_y;
};


class Vector {
 private:
  float begin_x;
  float begin_y;

  float proj_x;
  float proj_y;
 public:
  Vector();

  explicit Vector(float begin_x, float begin_y, float proj_x, float proj_y);

  float GetBeginX();

  float GetBeginY();

  float GetProjX();

  float GetProjY();

  void SetBeginX(float begin_x);

  void SetBeginY(float begin_y);

  void SetProjX(float proj_x);

  void SetProjY(float proj_y);

  float Length();

  float Angle();

  void Add(const Vector& v);

  void Sub(const Vector& v);

  void CounterDirect();

  void NumberMul(const float mul);

  void RotateLeft();

  void RotateRight();

  void Rotate(const float phi);

  ~Vector();
};























// struct Circle {
//   float center_x;
//   float center_y;
//   float radius;
//   bool is_filled;
// };




// int Circle_Render(SDL_Renderer* renderer, const Circle circle);

// int Vector_Render(SDL_Renderer* renderer, Vector vector, bool dot = true);



#endif /* geometry.h */
