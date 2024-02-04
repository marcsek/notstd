#include "mat3.h"
#include <math.h>

vec3 mat3_mult_vec3(const mat3 *m, const vec3 *v) {
  vec3 out = {0};
  out.x =
      m->matrix[0][0] * v->x + m->matrix[0][1] * v->y + m->matrix[0][2] * v->z;
  out.y =
      m->matrix[1][0] * v->x + m->matrix[1][1] * v->y + m->matrix[1][2] * v->z;
  out.z =
      m->matrix[2][0] * v->x + m->matrix[2][1] * v->y + m->matrix[2][2] * v->z;

  return out;
}

mat3 mat3_mult_mat3(const mat3 *lhsm, const mat3 *rhsm) {
  mat3 out = {0};
  for (int r_l = 0; r_l < 3; r_l++) {
    for (int c_r = 0; c_r < 3; c_r++) {
      out.matrix[r_l][c_r] = 0.0f;
      for (int i = 0; i < 3; i++) {
        out.matrix[r_l][c_r] += lhsm->matrix[r_l][i] * rhsm->matrix[i][c_r];
      }
    }
  }
  return out;
}

mat3 mat3_scale(float factor) {
  return (mat3){.matrix = {
                    factor,
                    0.0f,
                    0.0f,
                    0.0f,
                    factor,
                    0.0f,
                    0.0f,
                    0.0f,
                    1.0f,
                }};
}

mat3 mat3_scale_ind(float x, float y) {
  return (mat3){.matrix = {
                    x,
                    0.0f,
                    0.0f,
                    0.0f,
                    y,
                    0.0f,
                    0.0f,
                    0.0f,
                    1.0f,
                }};
}

mat3 mat3_identity() { return mat3_scale(1.0f); }

mat3 mat3_flipY() {
  return (mat3){
      .matrix = {1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f}};
}

mat3 mat3_rotation(float theta) {
  const float cost = cosf(theta);
  const float sint = sinf(theta);

  return (mat3){.matrix = {
                    cost,
                    -sint,
                    0.0f,
                    sint,
                    cost,
                    0.0f,
                    0.0f,
                    0.0f,
                    1.0f,
                }};
}

mat3 mat3_translation(const vec2 *v) {
  return (mat3){.matrix = {
                    1.0f,
                    0.0f,
                    v->x,
                    0.0f,
                    1.0f,
                    v->y,
                    0.0f,
                    0.0f,
                    1.0f,
                }};
}
