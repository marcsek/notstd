#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

linked_list *linked_list_create(cleanup_function *cf) {
  linked_list *ll = malloc(sizeof(linked_list));
  ll->size = 0;
  ll->head = NULL;
  ll->tail = NULL;
  ll->cf = cf == NULL ? free : cf;
  return ll;
}

linked_list *linked_list_create_h(list_value value, cleanup_function *cf) {
  if (value == NULL)
    return NULL;

  list_node *node = malloc(sizeof(list_node));
  node->next = NULL;
  node->value = value;

  linked_list *ll = malloc(sizeof(linked_list));
  ll->size = 1;
  ll->head = node;
  ll->tail = node;
  ll->cf = cf == NULL ? free : cf;
  return ll;
}

void linked_list_push(linked_list *ll, list_value value) {
  if (ll == NULL || value == NULL)
    return;

  list_node *node = malloc(sizeof(list_node));
  node->value = value;
  node->next = NULL;
  ll->size++;

  if (ll->tail == NULL) {
    ll->head = node;
    ll->tail = node;
    return;
  }

  list_node *prev = ll->tail;
  prev->next = node;
  ll->tail = node;
}

list_value linked_list_pop(linked_list *ll) {
  if (ll == NULL | ll->size < 1)
    return NULL;

  list_value to_return = NULL;

  if (ll->head == ll->tail) {
    to_return = ll->head->value;
    free(ll->head);
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;
    return to_return;
  }

  list_node *cur_node = ll->head;
  while (cur_node != NULL) {
    if (cur_node->next == ll->tail) {
      to_return = cur_node->next->value;
      free(cur_node->next);
      cur_node->next = NULL;
      ll->tail = cur_node;
      ll->size--;
      break;
    }
    cur_node = cur_node->next;
  }
  return to_return;
}

list_value linked_list_shift(linked_list *ll) {
  if (ll == NULL | ll->size < 1)
    return NULL;

  list_value to_return = NULL;

  to_return = ll->head->value;
  list_node *next_val = ll->head->next;
  free(ll->head);
  ll->head = next_val;

  if (ll->head == NULL)
    ll->tail = NULL;
  ll->size--;

  return to_return;
}

list_value linked_list_remove(linked_list *ll, list_node *node) {
  if (ll == NULL || node == NULL)
    return NULL;

  list_value to_return = NULL;

  if (node == ll->head) {
    to_return = ll->head->value;
    list_node *next_val = ll->head->next;
    free(ll->head);
    ll->head = next_val;

    if (ll->head == NULL)
      ll->tail = NULL;
    ll->size--;
    return to_return;
  }

  list_node *cur_node = ll->head;
  while (cur_node != NULL) {
    if (cur_node->next == node) {
      to_return = cur_node->next->value;
      list_node *next_val = cur_node->next->next;
      free(cur_node->next);
      cur_node->next = next_val;
      if (next_val == NULL)
        ll->tail = cur_node;
      ll->size--;
      break;
    }
    cur_node = cur_node->next;
  }
  return to_return;
}

list_value linked_list_idx(linked_list *ll, int idx) {
  if (ll == NULL || idx >= ll->size)
    return NULL;

  size_t cur_idx = 0;
  list_node *cur_node = ll->head;
  while (cur_node != NULL && cur_idx <= idx) {
    if (cur_idx == idx) {
      return cur_node->value;
    }
    cur_idx++;
    cur_node = cur_node->next;
  }
  return NULL;
}

void linked_list_destroy(linked_list *ll) {
  if (ll == NULL)
    return;

  list_node *cur_node = ll->head;
  while (cur_node != NULL) {
    list_node *next_node = cur_node->next;
    ll->cf(cur_node->value);
    free(cur_node);
    cur_node = next_node;
  }
  free(ll);
}

void dbg_print_linked_list(linked_list *ll) {
  if (ll == NULL || ll->size < 1) {
    printf("%p is empty", ll);
    return;
  }

  list_node *cur_node = ll->head;
  printf("head: %s, tail: %s, size: %lu \n\t", (char *)ll->head->value,
         (char *)ll->tail->value, ll->size);
  while (cur_node != NULL) {
    printf("%s -> ", (char *)cur_node->value);
    cur_node = cur_node->next;
  }
  printf("\n");
}
