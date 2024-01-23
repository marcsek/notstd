#include "linked_list.h"
#include "vec.h"
#include <notstd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

size_t get_hash_idx(hash_table *ht, const char *key) {
  return ht->hf(key, strlen(key)) % ht->size;
}

static size_t default_hash_func(const char *key, size_t size) {
  size_t hash_value = 0;
  for (size_t i = 0; i < size; i++) {
    hash_value += key[i];
    hash_value = hash_value * key[i];
  }
  return hash_value;
}

hash_table *hash_table_create(size_t size, hash_function *hf,
                              cleanup_function *cf) {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->size = size;
  ht->hf = hf == NULL ? default_hash_func : hf;
  ht->data = calloc(sizeof(linked_list), size);
  ht->cf = cf == NULL ? free : cf;

  return ht;
}

bool hash_table_set(hash_table *ht, const char *key, void *data) {
  if (ht == NULL || key == NULL | data == NULL)
    return false;

  size_t idx = get_hash_idx(ht, key);
  linked_list *ll = ht->data[idx];

  entry *ent = malloc(sizeof(entry));
  ent->value = data;
  ent->key = strndup(key, NSTD_HT_MAX_KEY_SIZE);

  if (ll != NULL) {
    list_node *cur_node = ll->head;
    while (cur_node != NULL) {
      if (strncmp(((entry *)cur_node->value)->key, key, NSTD_HT_MAX_KEY_SIZE) ==
          0) {
        entry *to_delete = linked_list_remove(ll, cur_node);
        free(to_delete->key);
        ht->cf(to_delete->value);
        break;
      }
      cur_node = cur_node->next;
    }
    linked_list_push(ll, ent);
    return true;
  }

  linked_list *new_ll = linked_list_create_h(ent, ht->cf);
  ht->data[idx] = new_ll;
  return true;
}

hash_table_value hash_table_get(hash_table *ht, const char *key) {
  if (ht == NULL || key == NULL)
    return NULL;

  size_t idx = get_hash_idx(ht, key);
  linked_list *ll = ht->data[idx];

  if (ll == NULL)
    return NULL;

  list_node *cur_node = ll->head;
  while (cur_node != NULL) {
    entry *ent = cur_node->value;
    if (strncmp(key, ent->key, NSTD_HT_MAX_KEY_SIZE) == 0) {
      return ent->value;
    }
    cur_node = cur_node->next;
  }
  return NULL;
}

vec *hash_table_values(hash_table *ht) {
  if (ht == NULL)
    return NULL;

  vec *v = vec_create(ht->size);

  for (size_t i = 0; i < ht->size; i++) {
    linked_list *ll = ht->data[i];
    if (ll == NULL)
      continue;

    list_node *cur_node = ll->head;
    while (cur_node != NULL) {
      entry *ent = cur_node->value;
      vec_push_back(v, ent->value);
      cur_node = cur_node->next;
    }
  }
  return v;
}

hash_table_value hash_table_delete(hash_table *ht, const char *key) {
  if (ht == NULL || key == NULL)
    return NULL;

  size_t idx = get_hash_idx(ht, key);
  linked_list *ll = ht->data[idx];

  if (ll == NULL)
    return NULL;

  list_node *cur_node = ll->head;
  while (cur_node != NULL) {
    entry *ent = cur_node->value;
    if (strncmp(key, ent->key, NSTD_HT_MAX_KEY_SIZE) == 0) {
      hash_table_value to_return = ent->value;
      free(ent->key);
      free(linked_list_remove(ll, cur_node));
      return to_return;
    }
    cur_node = cur_node->next;
  }
  return NULL;
}

void hash_table_destroy(hash_table *ht) {
  if (ht == NULL)
    return;

  for (size_t i = 0; i < ht->size; i++) {
    linked_list *ll = ht->data[i];
    linked_list_destroy(ll);
  }

  free(ht->data);
  free(ht);
}

void dbg_print_hash_table(hash_table *ht) {
  if (ht == NULL)
    return;

  for (size_t i = 0; i < ht->size; i++) {
    linked_list *ll = ht->data[i];
    if (ll == NULL)
      continue;

    printf("%lu: \n", i);
    list_node *cur_node = ll->head;
    while (cur_node != NULL) {
      entry *ent = cur_node->value;
      printf("\t %s -> %s\n", ent->key, (char *)ent->value);
      cur_node = cur_node->next;
    }
  }
}
