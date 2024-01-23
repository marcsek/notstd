#define NSTD_HASHTABLE_H
#define NSTD_HASHTABLE_C

#define NSTD_HT_MAX_KEY_SIZE 256

#include "vec.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef void *hash_table_value;

typedef size_t(hash_function)(const char *, size_t);
typedef void(cleanup_function)(hash_table_value);
typedef struct _hash_table hash_table;

hash_table *hash_table_create(size_t size, hash_function *hf,
                              cleanup_function *cf);
bool hash_table_set(hash_table *ht, const char *key, void *data);
hash_table_value hash_table_get(hash_table *ht, const char *key);
hash_table_value hash_table_delete(hash_table *ht, const char *key);
vec *hash_table_values(hash_table *ht);
void hash_table_destroy(hash_table *ht);

// For debugging...
void dbg_print_hash_table(hash_table *ht);
