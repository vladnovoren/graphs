#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL2/SDL.h>
#include <cassert>
#include <cmath>

const double VECTOR_CIRCLE_RADIUS = 3;
const double VECTOR_ARROW_P_PROJ = 10;
const double VECTOR_ARROW_MUL = 0.5;



struct Ranges {
  double min_x;
  double min_y;

  double max_x;
  double max_y;
};


class Vector {
 private:
  double begin_x;
  double begin_y;

  double proj_x;
  double proj_y;
 public:
  Vector();

  explicit Vector(double begin_x, double begin_y, double proj_x, double proj_y);

  double GetBeginX() const;

  double GetBeginY() const;

  double GetProjX() const;

  double GetProjY() const;

  void SetBeginX(double begin_x);

  void SetBeginY(double begin_y);

  void SetProjX(double proj_x);

  void SetProjY(double proj_y);

  double Length() const;

  double Angle() const;

  void ChangeLength(const double new_len);

  void Add(const Vector& v);

  void Sub(const Vector& v);

  void CounterDirect();

  void NumberMul(const double mul);

  void RotateLeft();

  void RotateRight();

  void Rotate(const double phi);

  ~Vector();
};























// struct Circle {
//   double center_x;
//   double center_y;
//   double radius;
//   bool is_filled;
// };




// int Circle_Render(SDL_Renderer* renderer, const Circle circle);

// int Vector_Render(SDL_Renderer* renderer, Vector vector, bool dot = true);



#endif /* geometry.h */
