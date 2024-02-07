#include "vec2.h"
#include <criterion/criterion.h>
#include <notstd.h>

Test(vec2tests, create) {
  vec2 v = (vec2){.x = 5.0f, .y = 3.0f};

  cr_expect(v.x == 5.0f, "Initial x parameter is correct.");
  cr_expect(v.y == 3.0f, "Initial y parameter is correct.");
}

Test(vec2tests, copy) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = vec2_copy(&v1);

  cr_expect(v2.x == 5.0f, "Copied x parameter is correct.");
  cr_expect(v2.y == 3.0f, "Copied y parameter is correct.");
  cr_expect(&v1 != &v2, "Copied poiters are different.");
}

Test(vec2tests, add) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = (vec2){.x = 2.0f, .y = 1.0f};
  vec2_add(&v1, &v2);

  cr_expect(v1.x == 7.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 4.0f, "Added y parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
}

Test(vec2tests, multiply) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = (vec2){.x = 2.0f, .y = 1.0f};
  vec2_mult(&v1, &v2);

  cr_expect(v1.x == 10.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 3.0f, "Added y parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
}

Test(vec2tests, multiply_scalar) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2_mult_s(&v1, 2.0f);

  cr_expect(v1.x == 10.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 6.0f, "Added y parameter is correct.");
}

Test(vec2tests, substract) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = (vec2){.x = 2.0f, .y = 1.0f};
  vec2_subs(&v1, &v2);

  cr_expect(v1.x == 3.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 2.0f, "Added y parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
}

Test(vec2tests, divide) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = (vec2){.x = 2.0f, .y = 1.0f};
  vec2_div(&v1, &v2);

  cr_expect(v1.x == 5.0f / 2.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 3.0f / 1.0f, "Added y parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
}

Test(vec2tests, divide_scalar) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = (vec2){.x = 2.0f, .y = 1.0f};
  vec2_div_s(&v1, 2.0f);

  cr_expect(v1.x == 5.0f / 2.0f, "Divided x parameter is correct.");
  cr_expect(v1.y == 3.0f / 2.0f, "Divided y parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
}

Test(vec2tests, divide_right) {
  vec2 v1 = (vec2){.x = 5.0f, .y = 3.0f};
  vec2 v2 = (vec2){.x = 2.0f, .y = 1.0f};
  vec2_divr(&v1, &v2);

  cr_expect(v1.x == 2.0f / 5.0f, "Added x parameter is correct.");
  cr_expect(v1.y == 1.0f / 3.0f, "Added y parameter is correct.");
  cr_expect(v2.x == 2.0f, "Second x parameter is correct.");
  cr_expect(v2.y == 1.0f, "Second y parameter is correct.");
}

Test(vec2tests, dot_product) {
  vec2 v1 = (vec2){.x = 1.0f, .y = 2.0f};
  vec2 v2 = (vec2){.x = 1.0f, .y = 5.0f};

  float r = vec2_dot_prod(&v1, &v2);

  cr_expect(r == 11.0f, "Dot product is correct.");
}

Test(vec2tests, interpolation) {
  vec2 v1 = (vec2){.x = 1.0f, .y = 2.0f};
  vec2 v2 = (vec2){.x = 3.0f, .y = 4.0f};

  vec2 r = vec2_interpolate_to(&v1, &v2, 0.5f);

  cr_expect(r.x == 2.0f, "Interpolated x parameter is correct.");
  cr_expect(r.y == 3.0f, "Interpolated y parameter is correct.");
}
