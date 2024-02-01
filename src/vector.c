#include <notstd.h>
#include <stdio.h>
#include <stdlib.h>

struct _vector {
  vector_value *data;
  size_t capacity;
  size_t size;
};

void vector_check_size_and_grow(vector *v) {
  if (v == NULL)
    return;

  if (v->size + 1 >= v->capacity) {
    v->data = realloc(v->data, v->capacity * sizeof(vector_value) * 2);
    v->capacity *= 2;
  }
}

vector *vector_create(size_t init_capacity) {
  vector *v = (vector *)malloc(sizeof(vector));
  vector_value *data =
      (vector_value *)malloc(init_capacity * sizeof(vector_value));

  v->data = data;
  v->size = 0;
  v->capacity = init_capacity;

  return v;
}

void vector_push_back(vector *v, vector_value value) {
  if (v == NULL || value == NULL || v->capacity == 0)
    return;

  vector_check_size_and_grow(v);

  v->data[v->size] = value;
  v->size++;
}

vector_value *vector_get_data(vector *v) {
  if (v == NULL)
    return NULL;

  return v->data;
}

size_t vector_get_size(vector *v) {
  if (v == NULL)
    return 0;

  return v->size;
}

void vector_destroy(vector *v) {
  free(v->data);
  free(v);
}

void dbg_print_vector(vector *v) {
  for (size_t i = 0; i < v->size; i++) {
    printf("%s, ", (char *)v->data[i]);
  }
  printf("\n");
}
