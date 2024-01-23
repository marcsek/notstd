#include "vec.h"
#include <notstd.h>
#include <string.h>

int main() {
  vec *v = vec_create(3);

  vec_push_back(v, "A");
  vec_push_back(v, "B");
  vec_push_back(v, "C");
  vec_push_back(v, "D");
  dbg_print_vec(v);
}
