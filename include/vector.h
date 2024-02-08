#ifndef NSTD_VECTOR_H
#define NSTD_VECTOR_H
#include <stdlib.h>

typedef struct _vector vector;
typedef void *vector_value;

typedef void(cleanup_function)(vector_value);

vector *vector_create(size_t init_capacity);
vector *vector_create_cf(size_t init_capacity, cleanup_function *cf);
void vector_push_back(vector *v, vector_value value);
vector_value *vector_get_data(const vector *v);
size_t vector_get_size(const vector *v);
void vector_destroy(vector *v);

// For debugging...
void dbg_print_vector(vector *v);

#endif
