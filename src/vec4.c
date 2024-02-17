#include "vec4.h"
#include "essentials.h"

vec4 vec4_copy(const vec4 *v) {
  return (vec4){
      .x = v->x,
      .y = v->y,
      .z = v->z,
      .w = v->w,
  };
}

void vec4_add(vec4 *v1, const vec4 *v2) {
  v1->x += v2->x;
  v1->y += v2->y;
  v1->z += v2->z;
  v1->w += v2->w;
}

void vec4_mult(vec4 *v1, const vec4 *v2) {
  v1->x *= v2->x;
  v1->y *= v2->y;
  v1->z *= v2->z;
  v1->w *= v2->w;
}

void vec4_mult_s(vec4 *v1, float scalar) {
  v1->x *= scalar;
  v1->y *= scalar;
  v1->z *= scalar;
  v1->w *= scalar;
}

void vec4_subs(vec4 *v1, const vec4 *v2) {
  v1->x -= v2->x;
  v1->y -= v2->y;
  v1->z -= v2->z;
  v1->w -= v2->w;
}

void vec4_div(vec4 *v1, const vec4 *v2) {
  v1->x /= v2->x;
  v1->y /= v2->y;
  v1->z /= v2->z;
  v1->w /= v2->w;
}

void vec4_div_s(vec4 *v1, float scalar) {
  v1->x /= scalar;
  v1->y /= scalar;
  v1->z /= scalar;
  v1->w /= scalar;
}

void vec4_divr(vec4 *v1, const vec4 *v2) {
  v1->x = v2->x / v1->x;
  v1->y = v2->y / v1->y;
  v1->z = v2->z / v1->z;
  v1->w = v2->w / v1->w;
}

vec4 vec4_interpolate_to(const vec4 *v, const vec4 *dest, float aplha) {
  vec4 res = vec4_copy(dest);
  vec4_subs(&res, v);
  vec4_mult_s(&res, aplha);
  vec4_add(&res, v);
  return res;
}

vec4 vec4_saturate(const vec4 *v) {
  return (vec4){
      .x = MIN(1.0f, MAX(0.0f, v->x)),
      .y = MIN(1.0f, MAX(0.0f, v->y)),
      .z = MIN(1.0f, MAX(0.0f, v->z)),
      .w = MIN(1.0f, MAX(0.0f, v->w)),
  };
}
