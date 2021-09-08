#include "geometry.h"


Vector::Vector() {

}


Vector::Vector(double begin_x, double begin_y, double proj_x, double proj_y) {
  this->begin_x = begin_x;
  this->begin_y = begin_y;
  this->proj_x = proj_x;
  this->proj_y = proj_y;
}


double Vector::GetBeginX() const {
  return begin_x;
}


double Vector::GetBeginY() const {
  return begin_y;
}


double Vector::GetProjX() const {
  return proj_x;
}


double Vector::GetProjY() const {
  return proj_y;
}


void Vector::SetBeginX(double begin_x) {
  this->begin_x = begin_x;
}


void Vector::SetBeginY(double begin_y) {
  this->begin_y = begin_y;
}


void Vector::SetProjX(double proj_x) {
  this->proj_x = proj_x;
}


void Vector::SetProjY(double proj_y) {
  this->proj_y = proj_y;
}


double Vector::Length() const {
  return sqrt(proj_x * proj_x + proj_y * proj_y);
}


double Vector::Angle() const {
  return atan2(proj_y, proj_x);
}


void Vector::ChangeLength(const double new_len) {
  double mul = double(new_len / Length());
  NumberMul(mul);
}


void Vector::Add(const Vector& v) {
  this->proj_x += v.proj_x;
  this->proj_y += v.proj_y;
}


void Vector::Sub(const Vector& v) {
  this->proj_x -= v.proj_x;
  this->proj_y -= v.proj_y;
}


void Vector::CounterDirect() {
  begin_x += proj_x;
  begin_y += proj_y;
  proj_x *= -1;
  proj_y *= -1;
}


void Vector::NumberMul(const double mul) {
  proj_x *= mul;
  proj_y *= mul;
}


void Vector::RotateLeft() {
  double temp = proj_x;
  proj_x = -proj_y;
  proj_y = temp;
}


void Vector::RotateRight() {
  double temp = proj_x;
  proj_x = proj_y;
  proj_y = -temp;
}


void Vector::Rotate(const double phi) {
  double length = Length();
  double angle = Angle() + phi;
  proj_x = cos(angle) * length;
  proj_y = sin(angle) * length;
}


Vector::~Vector() {

}















// int Circle_Render(SDL_Renderer* renderer, const Circle circle) {
//   assert(renderer);

//   int err_code = 0;

//   double old_x = -circle.radius,
//          old_y = 0,
//          cur_x = old_x + 1,
//          cur_y = 0;

//   double sqr_radius = pow(circle.radius, 2);
//   for (; cur_x <= circle.radius; ++cur_x) {
//     cur_y = sqrt(sqr_radius - cur_x * cur_x);

//     err_code = SDL_RenderDrawLineF(renderer, circle.center_x + old_x, circle.center_y + old_y,
//                                              circle.center_x + cur_x, circle.center_y + cur_y);
//     if (err_code)
//       break;

//     err_code = SDL_RenderDrawLineF(renderer, circle.center_x + old_x, circle.center_y - old_y,
//                                              circle.center_x + cur_x, circle.center_y - cur_y);
//     if (err_code)
//       break;

//     if (circle.is_filled) {
//       err_code = SDL_RenderDrawLineF(renderer, circle.center_x + cur_x, circle.center_y + cur_y,
//                                                circle.center_x + cur_x, circle.center_y - cur_y);
//       if (err_code)
//         break;
//     }

//     old_x = cur_x;
//     old_y = cur_y;
//   }

//   if (err_code)
//     return GetSdlErr(err_code);

//   return 0;
// }


// int Vector_Render(SDL_Renderer* renderer, Vector vector, bool dot) {
//   assert(renderer);

//   double vector_end_x = vector.start_x + vector.proj_x,
//         vector_end_y = vector.start_y + vector.proj_y;

//   int err_code = SDL_RenderDrawLineF(renderer, vector.start_x, vector.start_y, vector_end_x, vector_end_y);
//   if (err_code)
//     return GetSdlErr(err_code);

//   if (dot) {
//     err_code = Circle_Render(renderer, {vector.start_x, vector.start_y, VECTOR_CIRCLE_RADIUS, true});
//     if (err_code)
//       return err_code;
//   }

//   double vector_phi = atan2(vector.proj_y, vector.proj_x);
//   double first_phi = vector_phi + VECTOR_ARROW_ANGLE;
//   double second_phi = vector_phi - VECTOR_ARROW_ANGLE;

//   double first_x = vector_end_x - VECTOR_ARRAW_LEN * cos(first_phi);
//   double first_y = vector_end_y - VECTOR_ARRAW_LEN * sin(first_phi);

//   double second_x = vector_end_x - VECTOR_ARRAW_LEN * cos(second_phi);
//   double second_y = vector_end_y - VECTOR_ARRAW_LEN * sin(second_phi);

//   err_code = SDL_RenderDrawLineF(renderer, vector_end_x, vector_end_y, first_x, first_y);
//   if (err_code)
//     return GetSdlErr(err_code);

//   err_code = SDL_RenderDrawLineF(renderer, vector_end_x, vector_end_y, second_x, second_y);
//   if (err_code)
//     return GetSdlErr(err_code);
  
//   return 0;
// }


// bool VectorsEqual(const Vector* a, const Vector* b) {
//   return a->start_x == b->start_x &&
//          a->start_y == b->start_y &&
//          a->proj_x  == b->proj_x  &&
//          a->proj_y  == b->proj_y;
// }
