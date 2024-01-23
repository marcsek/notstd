#ifndef NSTD_LINKED_LIST_H
#define NSTD_LINKED_LIST_H

#include <stdlib.h>

typedef void *list_value;

typedef void(cleanup_function)(list_value);

typedef struct _list_node {
  list_value value;
  struct _list_node *next;
} list_node;

typedef struct _linked_list {
  size_t size;
  list_node *head;
  list_node *tail;
  cleanup_function *cf;
} linked_list;

linked_list *linked_list_create(cleanup_function *cf);
linked_list *linked_list_create_h(list_value value, cleanup_function *cf);
void linked_list_push(linked_list *ll, list_value value);
list_value linked_list_pop(linked_list *ll);
list_value linked_list_shift(linked_list *ll);
list_value linked_list_remove(linked_list *ll, list_node *node);
list_value linked_list_idx(linked_list *ll, int idx);
void linked_list_destroy(linked_list *ll);

// For debugging...
void dbg_print_linked_list(linked_list *ll);

#endif
