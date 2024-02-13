#include "vec3.h"
#include "essentials.h"
#include <math.h>

vec3 vec3_copy(const vec3 *v) {
  return (vec3){
      .x = v->x,
      .y = v->y,
      .z = v->z,
  };
}

void vec3_add(vec3 *v1, const vec3 *v2) {
  v1->x += v2->x;
  v1->y += v2->y;
  v1->z += v2->z;
}

void vec3_mult(vec3 *v1, const vec3 *v2) {
  v1->x *= v2->x;
  v1->y *= v2->y;
  v1->z *= v2->z;
}

void vec3_mult_s(vec3 *v1, float scalar) {
  v1->x *= scalar;
  v1->y *= scalar;
  v1->z *= scalar;
}

void vec3_subs(vec3 *v1, const vec3 *v2) {
  v1->x -= v2->x;
  v1->y -= v2->y;
  v1->z -= v2->z;
}

void vec3_div(vec3 *v1, const vec3 *v2) {
  v1->x /= v2->x;
  v1->y /= v2->y;
  v1->z /= v2->z;
}

void vec3_div_s(vec3 *v1, float scalar) {
  v1->x /= scalar;
  v1->y /= scalar;
  v1->z /= scalar;
}

void vec3_divr(vec3 *v1, const vec3 *v2) {
  v1->x = v2->x / v1->x;
  v1->y = v2->y / v1->y;
  v1->z = v2->z / v1->z;
}

float vec3_length(const vec3 *v) {
  return sqrtf(powf(v->x, 2) + powf(v->y, 2) + powf(v->z, 2));
}

float vec3_dot_prod(const vec3 *v1, const vec3 *v2) {
  return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

vec3 vec3_cross_prod(const vec3 *v1, const vec3 *v2) {
  return (vec3){
      .x = v1->y * v2->z - v1->z * v2->y,
      .y = v1->z * v2->x - v1->x * v2->z,
      .z = v1->x * v2->y - v1->y * v2->x,
  };
}

vec3 vec3_interpolate_to(const vec3 *v, const vec3 *dest, float aplha) {
  vec3 res = vec3_copy(dest);
  vec3_subs(&res, v);
  vec3_mult_s(&res, aplha);
  vec3_add(&res, v);
  return res;
}

vec3 vec3_saturate(const vec3 *v) {
  return (vec3){
      .x = MIN(1.0f, MAX(0.0f, v->x)),
      .y = MIN(1.0f, MAX(0.0f, v->y)),
      .z = MIN(1.0f, MAX(0.0f, v->z)),
  };
}

vec3 vec3_normalized(const vec3 *v) {
  const float length = vec3_length(v);

  return (vec3){
      .x = v->x / length,
      .y = v->y / length,
      .z = v->z / length,
  };
}
