#include "mat3.h"
#include <criterion/criterion.h>
#include <math.h>
#include <notstd.h>

Test(mat3tests, create) {
  mat3 m = mat3_identity();

  float r1[3] = {1.0f, 0.0f, 0.0f};
  float r2[3] = {0.0f, 1.0f, 0.0f};
  float r3[3] = {0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 3 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 3 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 3 * sizeof(float),
                   "Initial row3 is correct.");
}

Test(mat3tests, scale) {
  mat3 m = mat3_scale(2.0f);

  float r1[3] = {2.0f, 0.0f, 0.0f};
  float r2[3] = {0.0f, 2.0f, 0.0f};
  float r3[3] = {0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 3 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 3 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 3 * sizeof(float),
                   "Initial row3 is correct.");
}

Test(mat3tests, flipY) {
  mat3 m = mat3_flipY();

  float r1[3] = {1.0f, 0.0f, 0.0f};
  float r2[3] = {0.0f, -1.0f, 0.0f};
  float r3[3] = {0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 3 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 3 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 3 * sizeof(float),
                   "Initial row3 is correct.");
}

Test(mat3tests, rotationZ) {
  float theta = 0.5f;
  mat3 m = mat3_rotationZ(theta);

  float r1[3] = {cosf(theta), -sinf(theta), 0.0f};
  float r2[3] = {sinf(theta), cosf(theta), 0.0f};
  float r3[3] = {0.0f, 0.0f, 1.0f};

  cr_expect_arr_eq(m.matrix[0], r1, 3 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(m.matrix[1], r2, 3 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(m.matrix[2], r3, 3 * sizeof(float),
                   "Initial row3 is correct.");
}

Test(mat3tests, multiply_vec3) {
  mat3 m = (mat3){.matrix = {
                      {2.0f, 3.0f, 4.0f},
                      {6.0f, 7.0f, 3.0f},
                      {2.0f, 1.0f, 5.0f},
                  }};
  vec3 r = mat3_mult_vec3(&m, &(vec3){3.0f, 2.0f, 4.0f});
  cr_expect(r.x == 28.0f, "Vec3 x component is correct.");
  cr_expect(r.y == 44.0f, "Vec3 y component is correct.");
  cr_expect(r.z == 28.0f, "Vec3 z component is correct.");
}

Test(mat3tests, multiply_mat3) {
  mat3 m = (mat3){.matrix = {
                      {2.0f, 3.0f, 4.0f},
                      {6.0f, 7.0f, 3.0f},
                      {2.0f, 1.0f, 5.0f},
                  }};
  mat3 r = mat3_mult_mat3(&m, &(mat3){.matrix = {
                                          {3.0f, 9.0f, 2.0f},
                                          {4.0f, 5.0f, 8.0f},
                                          {2.0f, 1.0f, 4.0f},
                                      }});

  float r1[3] = {26.0f, 37.0f, 44.0f};
  float r2[3] = {52.0f, 92.0f, 80.0f};
  float r3[3] = {20.0f, 28.0f, 32.0f};

  cr_expect_arr_eq(r.matrix[0], r1, 3 * sizeof(float),
                   "Initial row1 is correct.");
  cr_expect_arr_eq(r.matrix[1], r2, 3 * sizeof(float),
                   "Initial row2 is correct.");
  cr_expect_arr_eq(r.matrix[2], r3, 3 * sizeof(float),
                   "Initial row3 is correct.");
}
