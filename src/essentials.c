#include "essentials.h"

void nstd_swap(void **v1, void **v2) {
  void *temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}
