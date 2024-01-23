#include "vec.h"
#include <criterion/criterion.h>
#include <notstd.h>
#include <stdio.h>

static void cf(void *ptr) {}

typedef struct entry {
  char *key;
  hash_table_value value;
} entry;

struct _hash_table {
  size_t size;
  linked_list **data;
  hash_function *hf;
  cleanup_function *cf;
};

size_t hash_func(const char *key, size_t size) { return strlen(key); }

Test(hashtabletest, create) {
  hash_table *ht = hash_table_create(32, &hash_func, &cf);

  cr_expect_not_null(ht, "Hash table is initially not NULL.");
}

Test(hashtabletest, set) {
  hash_table *ht = hash_table_create(32, &hash_func, &cf);

  char *key1 = "A";
  char *val1 = "VA";

  hash_table_set(ht, key1, val1);

  cr_expect_not_null(ht->data[1], "Key exists.");
  cr_expect(((entry *)ht->data[1]->head->value)->value == val1,
            "Key has correct value.");

  char *key2 = "B";
  char *val2 = "VB";

  hash_table_set(ht, key2, val2);

  cr_expect_not_null(ht->data[1], "Key exists.");
  cr_expect(((entry *)ht->data[1]->tail->value)->value == val2,
            "Key has correct value.");

  char *val3 = "VA";
  cr_expect_not_null(ht->data[1], "Key exists.");
  cr_expect(((entry *)ht->data[1]->head->value)->value == val3,
            "Key has correct value.");
}

Test(hashtabletest, get) {
  hash_table *ht = hash_table_create(32, &hash_func, &cf);

  hash_table_value r0 = hash_table_get(ht, "DOESN'T EXIST");
  cr_expect_null(r0, "Empty table returns NULL.");

  char *key1 = "A";
  char *val1 = "VA";
  char *key2 = "B";
  char *val2 = "VB";
  char *key3 = "AA";
  char *val3 = "VAA";

  hash_table_set(ht, key1, val1);
  hash_table_set(ht, key2, val2);
  hash_table_set(ht, key3, val3);

  hash_table_value r1 = hash_table_get(ht, key1);
  hash_table_value r2 = hash_table_get(ht, key2);
  hash_table_value r3 = hash_table_get(ht, key3);
  hash_table_value r4 = hash_table_get(ht, "DOESN'T EXIST");

  cr_expect_not_null(r1, "Return value is not NULL.");
  cr_expect_not_null(r2, "Return value is not NULL.");
  cr_expect_not_null(r3, "Return value is not NULL.");
  cr_expect_null(r4, "Return value is not NULL.");

  cr_expect(r1 == val1, "Return value is correct.");
  cr_expect(r2 == val2, "Return value is correct.");
  cr_expect(r3 == val3, "Return value is correct.");
}

Test(hashtabletest, delete) {
  hash_table *ht = hash_table_create(32, &hash_func, &cf);

  hash_table_value r0 = hash_table_delete(ht, "DOESN'T EXIST");
  cr_expect_null(r0, "Deleting on empty table returns NULL.");

  char *key1 = "A";
  char *val1 = "VA";
  char *key2 = "B";
  char *val2 = "VB";
  char *key3 = "AA";
  char *val3 = "VAA";

  hash_table_set(ht, key1, val1);
  hash_table_set(ht, key2, val2);
  hash_table_set(ht, key3, val3);

  hash_table_value r1 = hash_table_delete(ht, key1);
  hash_table_value r2 = hash_table_delete(ht, key2);
  hash_table_value r3 = hash_table_delete(ht, key3);
  hash_table_value r4 = hash_table_delete(ht, "DOESN'T EXIST");

  cr_expect_not_null(r1, "Deleted value is not NULL.");
  cr_expect_not_null(r2, "Deleted value is not NULL.");
  cr_expect_not_null(r3, "Deleted value is not NULL.");
  cr_expect_null(r4, "Deleted non existent value is NULL.");

  cr_expect(r1 == val1, "Deleted value is correct.");
  cr_expect(r2 == val2, "Deleted value is correct.");
  cr_expect(r3 == val3, "Deleted value is correct.");
}

Test(hashtabletest, values) {
  hash_table *ht = hash_table_create(32, &hash_func, &cf);

  char *key1 = "A";
  char *val1 = "VA";
  char *key2 = "B";
  char *val2 = "VB";
  char *key3 = "AA";
  char *val3 = "VAA";

  hash_table_set(ht, key1, val1);
  hash_table_set(ht, key2, val2);
  hash_table_set(ht, key3, val3);

  vec *v = hash_table_values(ht);
  hash_table_value *data = (hash_table_value *)vec_get_data(v);

  cr_expect(data[0] == val1, "Data is set correctly");
  cr_expect(data[1] == val2, "Data is set correctly");
  cr_expect(data[2] == val3, "Data is set correctly");
  cr_expect(vec_get_size(v) == 3, "Size is correct");
}
