#include "vec3.h"
#include <criterion/criterion.h>
#include <notstd.h>

Test(vec3tests, create) {
  vec3 v = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};

  cr_expect(v.x == 5.0f, "Initial x parameter is correct.");
  cr_expect(v.y == 3.0f, "Initial y parameter is correct.");
  cr_expect(v.z == 2.0f, "Initial z parameter is correct.");
}

Test(vec3tests, copy) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = vec3_copy(&v1);

  cr_expect(v2.x == 5.0f, "Copied x parameter is correct.");
  cr_expect(v2.y == 3.0f, "Copied y parameter is correct.");
  cr_expect(v2.z == 2.0f, "Copied z parameter is correct.");
  cr_expect(&v1 != &v2, "Copied poiters are different.");
}

Test(vec3tests, add) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 1.0f, .z = 6.0f};
  vec3_add(&v1, &v2);

  cr_expect(v1.x == 7.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 4.0f, "Added y parameter is correct.");
  cr_expect(v1.z == 8.0f, "Added z parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
}

Test(vec3tests, multiply) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 1.0f, .z = 6.0f};
  vec3_mult(&v1, &v2);

  cr_expect(v1.x == 10.0f, "Multiplied x parameter is correct.");
  cr_expect(v1.y == 3.0f, "Multiplied y parameter is correct.");
  cr_expect(v1.z == 12.0f, "Multiplied z parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
}

Test(vec3tests, multiply_scalar) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3_mult_s(&v1, 2.0f);

  cr_expect(v1.x == 10.0f, "Scaled x parameter is correct.");
  cr_expect(v1.y == 6.0f, "Scaled y parameter is correct.");
  cr_expect(v1.z == 4.0f, "Scaled z parameter is correct.");
}

Test(vec3tests, substract) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 1.0f, .z = 6.0f};
  vec3_subs(&v1, &v2);

  cr_expect(v1.x == 3.0f, "Substracted x parameter is correct.");
  cr_expect(v1.y == 2.0f, "Substracted y parameter is correct.");
  cr_expect(v1.z == -4.0f, "Substracted z parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
}

Test(vec3tests, divide) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 1.0f, .z = 6.0f};
  vec3_div(&v1, &v2);

  cr_expect(v1.x == 5.0f / 2.0f, "Divided x parameter is correct.");
  cr_expect(v1.y == 3.0f / 1.0f, "Divided y parameter is correct.");
  cr_expect(v1.z == 2.0f / 6.0f, "Divided z parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
}

Test(vec3tests, divide_scalar) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 1.0f, .z = 6.0f};
  vec3_div_s(&v1, 2.0f);

  cr_expect(v1.x == 5.0f / 2.0f, "Divided x parameter is correct.");
  cr_expect(v1.y == 3.0f / 2.0f, "Divided y parameter is correct.");
  cr_expect(v1.z == 2.0f / 2.0f, "Divided z parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
}

Test(vec3tests, divide_right) {
  vec3 v1 = (vec3){.x = 5.0f, .y = 3.0f, .z = 2.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 1.0f, .z = 6.0f};
  vec3_divr(&v1, &v2);

  cr_expect(v1.x == 2.0f / 5.0f, "Divided right x parameter is correct.");
  cr_expect(v1.y == 1.0f / 3.0f, "Divided right y parameter is correct.");
  cr_expect(v1.z == 6.0f / 2.0f, "Divided right z parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
}

Test(vec3tests, dot_product) {
  vec3 v1 = (vec3){.x = 1.0f, .y = 2.0f, .z = 3.0f};
  vec3 v2 = (vec3){.x = 1.0f, .y = 5.0f, .z = 7.0f};

  float r = vec3_dot_prod(&v1, &v2);

  cr_expect(r == 32.0f, "Dot product is correct.");
}

Test(vec3tests, cross_product) {
  vec3 v1 = (vec3){.x = 1.0f, .y = 2.0f, .z = 3.0f};
  vec3 v2 = (vec3){.x = 1.0f, .y = 5.0f, .z = 7.0f};

  vec3 r = vec3_cross_prod(&v1, &v2);

  cr_expect(r.x == -1.0f, "Cross prod. x parameter is correct.");
  cr_expect(r.y == -4.0f, "Cross prod. y parameter is correct.");
  cr_expect(r.z == 3.0f, "Cross prod. z parameter is correct.");
}

Test(vec3tests, interpolation) {
  vec3 v1 = (vec3){.x = 1.0f, .y = 2.0f, .z = 3.0f};
  vec3 v2 = (vec3){.x = 2.0f, .y = 5.0f, .z = 7.0f};

  vec3 r = vec3_interpolate_to(&v1, &v2, 0.5f);

  cr_expect(r.x == 1.5f, "Interpolated x parameter is correct.");
  cr_expect(r.y == 3.5f, "Interpolated y parameter is correct.");
  cr_expect(r.z == 5.0f, "Interpolated z parameter is correct.");
}

Test(vec3tests, saturate) {
  vec3 v1 = (vec3){.x = 1.0f, .y = 2.0f, .z = -3.0f};

  vec3 r = vec3_saturate(&v1);

  cr_expect(r.x == 1.0f, "Saturated x parameter is correct.");
  cr_expect(r.y == 1.0f, "Saturated y parameter is correct.");
  cr_expect(r.z == 0.0f, "Saturated z parameter is correct.");
}

Test(vec3tests, length) {
  vec3 v1 = (vec3){.x = 3.0f, .y = 4.0f, .z = 0.0f};

  float r = vec3_length(&v1);

  cr_expect(r == 5.0f, "Length is correct.");
}

Test(vec3tests, normalized) {
  vec3 v1 = (vec3){.x = 3.0f, .y = 4.0f, .z = 0.0f};

  float l = vec3_length(&v1);
  vec3 r = vec3_normalized(&v1);

  cr_expect(r.x == 3.0f / l, "Normalized x parameter is correct.");
  cr_expect(r.y == 4.0f / l, "Normalized y parameter is correct.");
  cr_expect(r.z == 0.0f / l, "Normalized z parameter is correct.");
}
