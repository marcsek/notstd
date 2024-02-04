#include "vec3.h"

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

void vec3_divr(vec3 *v1, const vec3 *v2) {
  v1->x = v2->x / v1->x;
  v1->y = v2->y / v1->y;
  v1->z = v2->z / v1->z;
}
