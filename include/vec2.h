#ifndef NSTD_VEC2_H
#define NSTD_VEC2_H

typedef struct {
  float x;
  float y;
} vec2;

vec2 vec2_copy(const vec2 *v);

void vec2_add(vec2 *v1, const vec2 *v2);
void vec2_mult(vec2 *v1, const vec2 *v2);
void vec2_subs(vec2 *v1, const vec2 *v2);
void vec2_div(vec2 *v1, const vec2 *v2);
void vec2_divr(vec2 *v1, const vec2 *v2);

#endif