#ifndef NSTD_VEC4_H
#define NSTD_VEC4_H

typedef struct {
  float x;
  float y;
  float z;
  float w;
} vec4;

vec4 vec4_copy(const vec4 *v);

void vec4_add(vec4 *v1, const vec4 *v2);
void vec4_mult(vec4 *v1, const vec4 *v2);
void vec4_mult_s(vec4 *v1, float scalar);
void vec4_subs(vec4 *v1, const vec4 *v2);
void vec4_div(vec4 *v1, const vec4 *v2);
void vec4_div_s(vec4 *v1, float scalar);
void vec4_divr(vec4 *v1, const vec4 *v2);
vec4 vec4_interpolate_to(const vec4 *v, const vec4 *dest, float aplha);
vec4 vec4_saturate(const vec4 *v);

#endif
