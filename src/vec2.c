#include "vec2.h"
#include <math.h>

vec2 vec2_copy(const vec2 *v) {
  return (vec2){
      .x = v->x,
      .y = v->y,
  };
}

void vec2_add(vec2 *v1, const vec2 *v2) {
  v1->x += v2->x;
  v1->y += v2->y;
}

void vec2_mult(vec2 *v1, const vec2 *v2) {
  v1->x *= v2->x;
  v1->y *= v2->y;
}

void vec2_mult_s(vec2 *v1, float scalar) {
  v1->x *= scalar;
  v1->y *= scalar;
}

void vec2_subs(vec2 *v1, const vec2 *v2) {
  v1->x -= v2->x;
  v1->y -= v2->y;
}

void vec2_div(vec2 *v1, const vec2 *v2) {
  v1->x /= v2->x;
  v1->y /= v2->y;
}

void vec2_divr(vec2 *v1, const vec2 *v2) {
  v1->x = v2->x / v1->x;
  v1->y = v2->y / v1->y;
}

void vec2_rotate(vec2 *v, float angle) {
  const float cos_theta = cosf(angle);
  const float sin_theta = sinf(angle);

  const float new_x = v->x * cos_theta - v->y * sin_theta;
  v->y = v->x * sin_theta + v->y * cos_theta;
  v->x = new_x;
}
