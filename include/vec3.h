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
void vec3_div_s(vec3 *v1, float scalar);
void vec3_divr(vec3 *v1, const vec3 *v2);
float vec3_length(const vec3 *v);
float vec3_dot_prod(const vec3 *v1, const vec3 *v2);
vec3 vec3_cross_prod(const vec3 *v1, const vec3 *v2);
vec3 vec3_interpolate_to(const vec3 *v, const vec3 *dest, float aplha);
vec3 vec3_saturate(const vec3 *v);
vec3 vec3_normalized(const vec3 *v);

#endif
