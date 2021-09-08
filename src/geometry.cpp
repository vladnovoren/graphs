#include "geometry.h"


Vector::Vector() {

}


Vector::Vector(float begin_x, float begin_y, float proj_x, float proj_y) {
  this->begin_x = begin_x;
  this->begin_y = begin_y;
  this->proj_x = proj_x;
  this->proj_y = proj_y;
}


float Vector::GetBeginX() {
  return begin_x;
}


float Vector::GetBeginY() {
  return begin_y;
}


float Vector::GetProjX() {
  return proj_x;
}


float Vector::GetProjY() {
  return proj_y;
}


void Vector::SetBeginX(float begin_x) {
  this->begin_x = begin_x;
}


void Vector::SetBeginY(float begin_y) {
  this->begin_y = begin_y;
}


void Vector::SetProjX(float proj_x) {
  this->proj_x = proj_x;
}


void Vector::SetProjY(float proj_y) {
  this->proj_y = proj_y;
}


float Vector::Length() {
  return sqrt(proj_x * proj_x + proj_y * proj_y);
}


float Vector::Angle() {
  return atan2(proj_y, proj_x);
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
  proj_x *= -1;
  proj_y *= -1;
}


void Vector::NumberMul(const float mul) {
  proj_x *= mul;
  proj_y *= mul;
}


void Vector::RotateLeft() {
  float temp = proj_x;
  proj_x = -proj_y;
  proj_y = temp;
}


void Vector::RotateRight() {
  float temp = proj_x;
  proj_x = proj_y;
  proj_y = -temp;
}


void Vector::Rotate(const float phi) {
  float length = Length();
  float angle = Angle() + phi;
  proj_x = cos(angle) * length;
  proj_y = sin(angle) * length;
}


void ~Vector() {
  
}















// int Circle_Render(SDL_Renderer* renderer, const Circle circle) {
//   assert(renderer);

//   int err_code = 0;

//   double old_x = -circle.radius,
//          old_y = 0,
//          cur_x = old_x + 1,
//          cur_y = 0;

//   float sqr_radius = pow(circle.radius, 2);
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

//   float vector_end_x = vector.start_x + vector.proj_x,
//         vector_end_y = vector.start_y + vector.proj_y;

//   int err_code = SDL_RenderDrawLineF(renderer, vector.start_x, vector.start_y, vector_end_x, vector_end_y);
//   if (err_code)
//     return GetSdlErr(err_code);

//   if (dot) {
//     err_code = Circle_Render(renderer, {vector.start_x, vector.start_y, VECTOR_CIRCLE_RADIUS, true});
//     if (err_code)
//       return err_code;
//   }

//   float vector_phi = atan2(vector.proj_y, vector.proj_x);
//   float first_phi = vector_phi + VECTOR_ARROW_ANGLE;
//   float second_phi = vector_phi - VECTOR_ARROW_ANGLE;

//   float first_x = vector_end_x - VECTOR_ARRAW_LEN * cos(first_phi);
//   float first_y = vector_end_y - VECTOR_ARRAW_LEN * sin(first_phi);

//   float second_x = vector_end_x - VECTOR_ARRAW_LEN * cos(second_phi);
//   float second_y = vector_end_y - VECTOR_ARRAW_LEN * sin(second_phi);

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
