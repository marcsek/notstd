#include "mat4.h"
#include <math.h>

vec4 mat4_mult_vec4(const mat4 *m, const vec4 *v) {
  vec4 out = {0};
  out.x = m->matrix[0][0] * v->x + m->matrix[0][1] * v->y +
          m->matrix[0][2] * v->z + m->matrix[0][3] * v->w;
  out.y = m->matrix[1][0] * v->x + m->matrix[1][1] * v->y +
          m->matrix[1][2] * v->z + m->matrix[1][3] * v->w;
  out.z = m->matrix[2][0] * v->x + m->matrix[2][1] * v->y +
          m->matrix[2][2] * v->z + m->matrix[2][3] * v->w;
  out.w = m->matrix[3][0] * v->x + m->matrix[3][1] * v->y +
          m->matrix[3][2] * v->z + m->matrix[3][3] * v->w;

  return out;
}

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
                    {1.0f, 0.0f, 0.0f, v->x},
                    {0.0f, 1.0f, 0.0f, v->y},
                    {0.0f, 0.0f, 1.0f, v->z},
                    {0.0f, 0.0f, 0.0f, 1.0f},
                }};
}
