#include "./src/hashtable.h"
#include <stdio.h>
#include <string.h>

size_t hash_func(const char *key, size_t size) {
  // size_t hash_value = 0;
  // for (size_t i = 0; i < size; i++) {
  //   hash_value += key[i];
  //   hash_value = hash_value * key[i];
  // }
  // return hash_value;
  return strlen(key);
}

void moj_free(void *ptr) {
  printf("FREE %p\n", ptr);
  // free(ptr);
}

int main() {
  hash_table *ht = hash_table_create(1024, NULL, &moj_free);
  hash_table_set(ht, "A", "MAM A");
  hash_table_set(ht, "B", "MAM B");
  hash_table_set(ht, "AA", "MAM AA");

  dbg_print_hash_table(ht);
}
