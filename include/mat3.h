#ifndef NSTD_MAT3_H
#define NSTD_MAT3_H
#include "vec2.h"
#include "vec3.h"

typedef struct {
  float matrix[3][3];
} mat3;

vec3 mat3_mult_vec3(const mat3 *m, const vec3 *v);
mat3 mat3_mult_mat3(const mat3 *lhsm, const mat3 *rhsm);
mat3 mat3_scale(float factor);
mat3 mat3_scale_ind(float x, float y);
mat3 mat3_identity();
mat3 mat3_flipY();
mat3 mat3_rotation(float theta);
mat3 mat3_translation(const vec2 *v);

#endif
