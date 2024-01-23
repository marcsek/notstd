#include <notstd.h>
#include <stdio.h>
#include <stdlib.h>

struct _vec {
  vec_value *data;
  size_t capacity;
  size_t size;
};

void vec_check_size_and_grow(vec *v) {
  if (v == NULL)
    return;

  if (v->size + 1 >= v->capacity) {
    v->data = realloc(v->data, v->capacity * sizeof(vec_value) * 2);
    v->capacity *= 2;
  }
}

vec *vec_create(size_t init_capacity) {
  vec *v = (vec *)malloc(sizeof(vec));
  vec_value *data = (vec_value *)malloc(init_capacity * sizeof(vec_value));

  v->data = data;
  v->size = 0;
  v->capacity = init_capacity;

  return v;
}

void vec_push_back(vec *v, vec_value value) {
  if (v == NULL || value == NULL || v->capacity == 0)
    return;

  vec_check_size_and_grow(v);

  v->data[v->size] = value;
  v->size++;
}

vec_value *vec_get_data(vec *v) {
  if (v == NULL)
    return NULL;

  return v->data;
}

size_t vec_get_size(vec *v) {
  if (v == NULL)
    return 0;

  return v->size;
}

void vec_destroy(vec *v) {
  free(v->data);
  free(v);
}

void dbg_print_vec(vec *v) {
  for (size_t i = 0; i < v->size; i++) {
    printf("%s, ", (char *)v->data[i]);
  }
  printf("\n");
}
