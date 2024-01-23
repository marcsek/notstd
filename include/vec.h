#ifndef NSTD_VEC_H
#define NSTD_VEC_H
#include <stdlib.h>

typedef struct _vec vec;
typedef void *vec_value;

vec *vec_create(size_t init_size);
void vec_push_back(vec *v, vec_value value);
vec_value *vec_get_data(vec *v);
size_t vec_get_size(vec *v);
void vec_destroy(vec *v);

// For debugging...
void dbg_print_vec(vec *v);

#endif
