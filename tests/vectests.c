#include "vec.h"
#include <criterion/criterion.h>

struct _vec {
  vec_value *data;
  size_t capacity;
  size_t size;
};

Test(vectest, create) {
  vec *v = vec_create(10);
  cr_expect_not_null(v, "v is not NULL. (h)");

  cr_expect(v->capacity == 10, "Initial capacity is correct");
  cr_expect(v->size == 0, "Initial size is correct");
}

Test(vectest, push_back) {
  vec *v = vec_create(3);

  char *v1 = "A";
  char *v2 = "B";
  char *v3 = "C";

  vec_push_back(v, v1);

  cr_expect(v->data[0] == v1, "Data is set correctly");
  cr_expect(v->size == 1, "Size is correct after pushing");

  vec_push_back(v, v2);
  cr_expect(v->data[1] == v2, "Data is set correctly");
  cr_expect(v->size == 2, "Size is correct after pushing");

  vec_push_back(v, v2);
  cr_expect(v->data[2] == v2, "Can add same data multiple times");
  cr_expect(v->size == 3, "Size is correct after pushing");

  vec_push_back(v, v3);
  cr_expect(v->data[3] == v3, "Data is set correctly after resize");
  cr_expect(v->size == 4, "Size is correct after resize");
  cr_expect(v->capacity == 6, "Capacity is correct");
}

Test(vectest, get_data) {
  vec *v = vec_create(3);

  char *v1 = "A";
  char *v2 = "B";
  char *v3 = "C";

  vec_push_back(v, v1);
  vec_push_back(v, v2);
  vec_push_back(v, v2);
  vec_push_back(v, v3);

  vec_value *data = vec_get_data(v);
  cr_expect(data[0] == v1, "Data is set correctly");
  cr_expect(data[1] == v2, "Data is set correctly");
  cr_expect(data[2] == v2, "Data is set correctly");
  cr_expect(data[3] == v3, "Data is set correctly");
}
