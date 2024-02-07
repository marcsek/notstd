#ifndef NSTD_VEC2_H
#define NSTD_VEC2_H

typedef struct {
  float x;
  float y;
} vec2;

vec2 vec2_copy(const vec2 *v);

void vec2_add(vec2 *v1, const vec2 *v2);
void vec2_mult(vec2 *v1, const vec2 *v2);
void vec2_mult_s(vec2 *v1, float scalar);
void vec2_subs(vec2 *v1, const vec2 *v2);
void vec2_div(vec2 *v1, const vec2 *v2);
void vec2_div_s(vec2 *v1, float scalar);
void vec2_divr(vec2 *v1, const vec2 *v2);
void vec2_rotate(vec2 *v, float angle);
float vec2_dot_prod(const vec2 *v1, const vec2 *v2);
vec2 vec2_interpolate_to(const vec2 *v, const vec2 *dest, float aplha);

#endif
