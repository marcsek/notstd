#ifndef NSTD_VECTOR_H
#define NSTD_VECTOR_H
#include <stdlib.h>

typedef struct _vector vector;
typedef void *vector_value;

vector *vector_create(size_t init_size);
void vector_push_back(vector *v, vector_value value);
vector_value *vector_get_data(vector *v);
size_t vector_get_size(vector *v);
vector *vector_copy(vector *v);
void vector_destroy(vector *v);

// For debugging...
void dbg_print_vector(vector *v);

#endif
