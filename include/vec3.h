#ifndef NSTD_VEC3_H
#define NSTD_VEC3_H

typedef struct {
  float x;
  float y;
  float z;
} vec3;

vec3 vec3_copy(const vec3 *v);

void vec3_add(vec3 *v1, const vec3 *v2);
void vec3_mult(vec3 *v1, const vec3 *v2);
void vec3_mult_s(vec3 *v1, float scalar);
void vec3_subs(vec3 *v1, const vec3 *v2);
void vec3_div(vec3 *v1, const vec3 *v2);
void vec3_divr(vec3 *v1, const vec3 *v2);

#endif
