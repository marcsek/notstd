#ifndef NSTD_MAT4_H
#define NSTD_MAT4_H
#include "vec3.h"
#include "vec4.h"

typedef struct {
  float matrix[4][4];
} mat4;

vec4 mat4_mult_vec4(const mat4 *m, const vec4 *v);
mat4 mat4_mult_mat4(const mat4 *lhsm, const mat4 *rhsm);
mat4 mat4_scale(float factor);
mat4 mat4_scale_ind(float x, float y);
mat4 mat4_identity();
mat4 mat4_rotationZ(float theta);
mat4 mat4_rotationY(float theta);
mat4 mat4_rotationX(float theta);
mat4 mat4_translation(const vec3 *v);

#endif
