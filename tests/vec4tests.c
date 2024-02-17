#include "vec4.h"
#include <criterion/criterion.h>
#include <notstd.h>

Test(vec4tests, create) {
  vec4 v = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f};

  cr_expect(v.x == 5.0f, "Initial x parameter is correct.");
  cr_expect(v.y == 3.0f, "Initial y parameter is correct.");
  cr_expect(v.z == 2.0f, "Initial z parameter is correct.");
}

Test(vec4tests, copy) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = vec4_copy(&v1);

  cr_expect(v2.x == 5.0f, "Copied x parameter is correct.");
  cr_expect(v2.y == 3.0f, "Copied y parameter is correct.");
  cr_expect(v2.z == 2.0f, "Copied z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Copied w parameter is correct.");
  cr_expect(&v1 != &v2, "Copied poiters are different.");
}

Test(vec4tests, add) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 1.0f, .z = 6.0f, .w = 1.0f};
  vec4_add(&v1, &v2);

  cr_expect(v1.x == 7.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 4.0f, "Added y parameter is correct.");
  cr_expect(v1.z == 8.0f, "Added z parameter is correct.");
  cr_expect(v1.w == 2.0f, "Added w parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Second w parameter is correct.");
}

Test(vec4tests, multiply) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 1.0f, .z = 6.0f, .w = 1.0f};
  vec4_mult(&v1, &v2);

  cr_expect(v1.x == 10.0f, "Multiplied x parameter is correct.");
  cr_expect(v1.y == 3.0f, "Multiplied y parameter is correct.");
  cr_expect(v1.z == 12.0f, "Multiplied z parameter is correct.");
  cr_expect(v1.w == 1.0f, "Multiplied w parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Second w parameter is correct.");
}

Test(vec4tests, multiply_scalar) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4_mult_s(&v1, 2.0f);

  cr_expect(v1.x == 10.0f, "Scaled x parameter is correct.");
  cr_expect(v1.y == 6.0f, "Scaled y parameter is correct.");
  cr_expect(v1.z == 4.0f, "Scaled z parameter is correct.");
  cr_expect(v1.w == 2.0f, "Scaled w parameter is correct.");
}

Test(vec4tests, substract) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 1.0f, .z = 6.0f, .w = 1.0f};
  vec4_subs(&v1, &v2);

  cr_expect(v1.x == 3.0f, "Substracted x parameter is correct.");
  cr_expect(v1.y == 2.0f, "Substracted y parameter is correct.");
  cr_expect(v1.z == -4.0f, "Substracted z parameter is correct.");
  cr_expect(v1.w == 0.0f, "Substracted w parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Second w parameter is correct.");
}

Test(vec4tests, divide) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 1.0f, .z = 6.0f, .w = 1.0f};
  vec4_div(&v1, &v2);

  cr_expect(v1.x == 5.0f / 2.0f, "Divided x parameter is correct.");
  cr_expect(v1.y == 3.0f / 1.0f, "Divided y parameter is correct.");
  cr_expect(v1.z == 2.0f / 6.0f, "Divided z parameter is correct.");
  cr_expect(v1.w == 1.0f / 1.0f, "Divided w parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Second w parameter is correct.");
}

Test(vec4tests, divide_scalar) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 1.0f, .z = 6.0f, .w = 1.0f};
  vec4_div_s(&v1, 2.0f);

  cr_expect(v1.x == 5.0f / 2.0f, "Divided x parameter is correct.");
  cr_expect(v1.y == 3.0f / 2.0f, "Divided y parameter is correct.");
  cr_expect(v1.z == 2.0f / 2.0f, "Divided z parameter is correct.");
  cr_expect(v1.w == 1.0f / 2.0f, "Divided w parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Second w parameter is correct.");
}

Test(vec4tests, divide_right) {
  vec4 v1 = (vec4){.x = 5.0f, .y = 3.0f, .z = 2.0f, .w = 1.0f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 1.0f, .z = 6.0f, .w = 1.0f};
  vec4_divr(&v1, &v2);

  cr_expect(v1.x == 2.0f / 5.0f, "Divided right x parameter is correct.");
  cr_expect(v1.y == 1.0f / 3.0f, "Divided right y parameter is correct.");
  cr_expect(v1.z == 6.0f / 2.0f, "Divided right z parameter is correct.");
  cr_expect(v1.w == 1.0f / 1.0f, "Divided right w parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
  cr_expect(v2.z == 6.0f, "Second z parameter is correct.");
  cr_expect(v2.w == 1.0f, "Second w parameter is correct.");
}

Test(vec4tests, interpolation) {
  vec4 v1 = (vec4){.x = 1.0f, .y = 2.0f, .z = 3.0f, .w = 1.5f};
  vec4 v2 = (vec4){.x = 2.0f, .y = 5.0f, .z = 7.0f, .w = 3.5f};

  vec4 r = vec4_interpolate_to(&v1, &v2, 0.5f);

  cr_expect(r.x == 1.5f, "Interpolated x parameter is correct.");
  cr_expect(r.y == 3.5f, "Interpolated y parameter is correct.");
  cr_expect(r.z == 5.0f, "Interpolated z parameter is correct.");
  cr_expect(r.w == 2.5f, "Interpolated w parameter is correct.");
}

Test(vec4tests, saturate) {
  vec4 v1 = (vec4){.x = 1.0f, .y = 2.0f, .z = -3.0f, .w = 0.5f};

  vec4 r = vec4_saturate(&v1);

  cr_expect(r.x == 1.0f, "Saturated x parameter is correct.");
  cr_expect(r.y == 1.0f, "Saturated y parameter is correct.");
  cr_expect(r.z == 0.0f, "Saturated z parameter is correct.");
  cr_expect(r.w == 0.5f, "Saturated w parameter is correct.");
}
