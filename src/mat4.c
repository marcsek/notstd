#include "mat4.h"
#include <math.h>

mat4 mat4_mult_mat4(const mat4 *lhsm, const mat4 *rhsm) {
  mat4 out = {0};
  for (int r_l = 0; r_l < 4; r_l++) {
    for (int c_r = 0; c_r < 4; c_r++) {
      out.matrix[r_l][c_r] = 0.0f;
      for (int i = 0; i < 4; i++) {
        out.matrix[r_l][c_r] += lhsm->matrix[r_l][i] * rhsm->matrix[i][c_r];
      }
    }
  }
  return out;
}

mat4 mat4_scale(float factor) {
  return (mat4){.matrix = {
                    {factor, 0.0f, 0.0f, 0.0f},
                    {0.0f, factor, 0.0f, 0.0f},
                    {0.0f, 0.0f, factor, 0.0f},
                    {0.0f, 0.0f, 0.0f, 1.0f},
                }};
}

mat4 mat4_scale_ind(float x, float y) {
  return (mat4){.matrix = {
                    {x, 0.0f, 0.0f},
                    {0.0f, y, 0.0f},
                    {0.0f, 0.0f, 1.0f},
                }};
}

mat4 mat4_identity() { return mat4_scale(1.0f); }

mat4 mat4_rotationZ(float theta) {
  const float cost = cosf(theta);
  const float sint = sinf(theta);

  return (mat4){.matrix = {
                    {cost, sint, 0.0f, 0.0f},
                    {-sint, cost, 0.0f, 0.0f},
                    {0.0f, 0.0f, 1.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f, 1.0f},
                }};
}

mat4 mat4_rotationY(float theta) {
  const float cost = cosf(theta);
  const float sint = sinf(theta);

  return (mat4){.matrix = {
                    {cost, 0.0f, -sint, 0.0f},
                    {0.0f, 1.0f, 0.0f, 0.0f},
                    {sint, 0.0f, cost, 0.0f},
                    {0.0f, 0.0f, 0.0f, 1.0f},
                }};
}

mat4 mat4_rotationX(float theta) {
  const float cost = cosf(theta);
  const float sint = sinf(theta);

  return (mat4){.matrix = {
                    {1.0f, 0.0f, 0.0f, 0.0f},
                    {0.0f, cost, sint, 0.0f},
                    {0.0f, -sint, cost, 0.0f},
                    {0.0f, 0.0f, 0.0f, 1.0f},
                }};
}

mat4 mat4_translation(const vec3 *v) {
  return (mat4){.matrix = {
                    {1.0f, 0.0f, 0.0f, 0.0f},
                    {0.0f, 1.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 1.0f, 0.0f},
                    {v->x, v->y, v->z, 1.0f},
                }};
}
