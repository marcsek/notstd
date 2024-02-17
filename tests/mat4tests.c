#include "mat4.h"
#include <criterion/criterion.h>
#include <math.h>
#include <notstd.h>

Test(mat4tests, create) {
  mat4 m = mat4_identity();

  float r1[4] = {1.0f, 0.0f, 0.0f, 0.0f};
  float r2[4] = {0.0f, 1.0f, 0.0f, 0.0f};
  float r3[4] = {0.0f, 0.0f, 1.0f, 0.0f};
  float r4[4] = {0.0f, 0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 4 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 4 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 4 * sizeof(float),
                   "Initial row3 is correct.");
  cr_expect_arr_eq(m.matrix[3], r4, 4 * sizeof(float),
                   "Initial row4 is correct.");
}

Test(mat4tests, scale) {
  mat4 m = mat4_scale(2.0f);

  float r1[4] = {2.0f, 0.0f, 0.0f, 0.0f};
  float r2[4] = {0.0f, 2.0f, 0.0f, 0.0f};
  float r3[4] = {0.0f, 0.0f, 2.0f, 0.0f};
  float r4[4] = {0.0f, 0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 4 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 4 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 4 * sizeof(float),
                   "Initial row3 is correct.");
  cr_expect_arr_eq(m.matrix[3], r4, 4 * sizeof(float),
                   "Initial row4 is correct.");
}

Test(mat4tests, rotationZ) {
  float theta = 0.5f;
  mat4 m = mat4_rotationZ(theta);

  float r1[4] = {cosf(theta), sinf(theta), 0.0f, 0.0f};
  float r2[4] = {-sinf(theta), cosf(theta), 0.0f, 0.0f};
  float r3[4] = {0.0f, 0.0f, 1.0f, 0.0f};
  float r4[4] = {0.0f, 0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 4 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 4 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 4 * sizeof(float),
                   "Initial row3 is correct.");
  cr_expect_arr_eq(m.matrix[3], r4, 4 * sizeof(float),
                   "Initial row4 is correct.");
}

Test(mat4tests, multiply_vec4) {
  mat4 m = (mat4){.matrix = {
                      {2.0f, 3.0f, 4.0f, 5.0f},
                      {6.0f, 7.0f, 3.0f, 0.0f},
                      {2.0f, 1.0f, 5.0f, 8.0f},
                      {8.0f, 3.0f, 2.0f, 1.0f},
                  }};

  vec4 r = mat4_mult_vec4(&m, &(vec4){3.0f, 9.0f, 2.0f, 1.0f});
  cr_expect(r.x == 46.0f, "Vec4 x component is correct.");
  cr_expect(r.y == 87.0f, "Vec4 y component is correct.");
  cr_expect(r.z == 33.0f, "Vec4 z component is correct.");
  cr_expect(r.w == 56.0f, "Vec4 w component is correct.");
}

Test(mat4tests, multiply_mat4) {
  mat4 m = (mat4){.matrix = {
                      {2.0f, 3.0f, 4.0f, 5.0f},
                      {6.0f, 7.0f, 3.0f, 0.0f},
                      {2.0f, 1.0f, 5.0f, 8.0f},
                      {8.0f, 3.0f, 2.0f, 1.0f},
                  }};
  mat4 r = mat4_mult_mat4(&m, &(mat4){.matrix = {
                                          {3.0f, 9.0f, 2.0f, 1.0f},
                                          {4.0f, 5.0f, 8.0f, 0.0f},
                                          {2.0f, 1.0f, 4.0f, 2.0f},
                                          {2.0f, 8.0f, 8.0f, 3.0f},
                                      }});

  float r1[4] = {36.0f, 77.0f, 84.0f, 25.0f};
  float r2[4] = {52.0f, 92.0f, 80.0f, 12.0f};
  float r3[4] = {36.0f, 92.0f, 96.0f, 36.0f};
  float r4[4] = {42.0f, 97.0f, 56.0f, 15.0f};

  cr_expect_arr_eq(r.matrix[0], r1, 4 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(r.matrix[1], r2, 4 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(r.matrix[2], r3, 4 * sizeof(float),
                   "Initial row3 is correct.");
  cr_expect_arr_eq(r.matrix[3], r4, 4 * sizeof(float),
                   "Initial row4 is correct.");
}
