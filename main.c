#include "vec.h"
#include <notstd.h>
#include <stdio.h>
#include <string.h>

int main() {
  vec *v = vec_create(3);

  printf("Nazdar\n");
  vec_push_back(v, "A");
  vec_push_back(v, "B");
  vec_push_back(v, "C");
  vec_push_back(v, "D");
  vec_print(v);
}
