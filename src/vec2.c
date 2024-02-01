#include "vec2.h"

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
