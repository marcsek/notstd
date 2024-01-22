#include <criterion/criterion.h>

#include "../src/linked_list.h"

void cf(void *ptr) {}

Test(linkedlisttest, create) {
  linked_list *ll = linked_list_create_h("A", cf);
  cr_expect_not_null(ll, "ll is not NULL. (h)");

  ll = linked_list_create(cf);
  cr_expect_not_null(ll, "ll is not NULL.");
}

Test(linkedlisttest, push) {
  linked_list *ll = linked_list_create(cf);

  cr_expect_null(ll->head, "Head is initially NULL.");
  cr_expect_null(ll->tail, "Tail is initially NULL.");
  cr_expect(ll->size == 0, "Size is initially zero.");

  char *item = "A";
  linked_list_push(ll, item);

  cr_expect_not_null(ll->head, "Head is set.");
  cr_expect_not_null(ll->tail, "Tail is set.");
  cr_expect(ll->head->value == item, "Head has correct value.");
  cr_expect(ll->tail->value == item, "Tail has correct value.");
  cr_expect(ll->size == 1, "Size is correct.");

  char *item2 = "B";
  linked_list_push(ll, item2);

  cr_expect(ll->head->value == item, "Head has correct value.");
  cr_expect(ll->tail->value == item2, "Tail has correct value.");
  cr_expect(ll->size == 2, "Size is correct.");

  char *item3 = "C";
  linked_list_push(ll, item3);

  cr_expect(ll->head->value == item, "Head has correct value.");
  cr_expect(ll->head->next->value == item2, "Middle has correct value.");
  cr_expect(ll->tail->value == item3, "Tail has correct value.");
  cr_expect(ll->size == 3, "Size is correct.");
}

Test(linkedlisttest, pop) {
  linked_list *ll = linked_list_create(cf);

  char *item = "A";
  char *item2 = "B";
  linked_list_push(ll, item);
  linked_list_push(ll, item2);

  void *ret = linked_list_pop(ll);

  cr_expect_not_null(ll->tail, "Tail is not NULL.");
  cr_expect_not_null(ll->head, "Head is not NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ll->tail->value == item, "Tail has correct value.");
  cr_expect(ll->head->value == item, "Head has correct value.");
  cr_expect(ret == item2, "Return value is correct.");
  cr_expect(ll->size == 1, "Size is correct.");

  ret = linked_list_pop(ll);

  cr_expect_null(ll->tail, "Tail is NULL.");
  cr_expect_null(ll->head, "Head is NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ret == item, "Return value is correct.");
  cr_expect(ll->size == 0, "Size is correct.");
}

Test(linkedlisttest, shift) {
  linked_list *ll = linked_list_create(cf);
  char *item = "A";
  char *item2 = "B";
  linked_list_push(ll, item);
  linked_list_push(ll, item2);

  void *ret = linked_list_shift(ll);

  cr_expect_not_null(ll->tail, "Tail is not NULL.");
  cr_expect_not_null(ll->head, "Head is not NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ll->tail->value == item2, "Tail has correct value.");
  cr_expect(ll->head->value == item2, "Head has correct value.");
  cr_expect(ret == item, "Return value is correct.");
  cr_expect(ll->size == 1, "Size is correct.");

  ret = linked_list_shift(ll);

  cr_expect_null(ll->tail, "Tail is NULL.");
  cr_expect_null(ll->head, "Head is NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ret == item2, "Return value is correct.");
  cr_expect(ll->size == 0, "Size is correct.");
}

Test(linkedlisttest, remove) {
  linked_list *ll = linked_list_create(cf);
  char *item = "A";
  char *item2 = "B";
  linked_list_push(ll, item);
  linked_list_push(ll, item2);

  void *ret = linked_list_remove(ll, ll->head);

  cr_expect_not_null(ll->tail, "Tail is not NULL.");
  cr_expect_not_null(ll->head, "Head is not NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ll->tail->value == item2, "Tail has correct value.");
  cr_expect(ll->head->value == item2, "Head has correct value.");
  cr_expect(ret == item, "Return value is correct.");
  cr_expect(ll->size == 1, "Size is correct.");

  ll = linked_list_create(cf);
  linked_list_push(ll, item);
  linked_list_push(ll, item2);

  ret = linked_list_remove(ll, ll->tail);

  cr_expect_not_null(ll->tail, "Tail is not NULL.");
  cr_expect_not_null(ll->head, "Head is not NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ll->tail->value == item, "Tail has correct value.");
  cr_expect(ll->head->value == item, "Head has correct value.");
  cr_expect(ret == item2, "Return value is correct.");
  cr_expect(ll->size == 1, "Size is correct.");

  ll = linked_list_create(cf);
  char *item3 = "C";
  linked_list_push(ll, item);
  linked_list_push(ll, item2);
  linked_list_push(ll, item3);

  ret = linked_list_remove(ll, ll->head->next);
  cr_expect_not_null(ll->tail, "Tail is not NULL.");
  cr_expect_not_null(ll->head, "Head is not NULL.");
  cr_expect_not_null(ret, "Return value is not NULL.");
  cr_expect(ll->tail->value == item3, "Tail has correct value.");
  cr_expect(ll->head->value == item, "Head has correct value.");
  cr_expect(ret == item2, "Return value is correct.");
  cr_expect(ll->size == 2, "Size is correct.");
}

Test(linkedlisttest, idx) {
  linked_list *ll = linked_list_create(cf);
  char *item = "A";
  char *item2 = "B";
  char *item3 = "C";

  linked_list_push(ll, item);
  linked_list_push(ll, item2);
  linked_list_push(ll, item3);

  void *ret0 = linked_list_idx(ll, 0);
  void *ret1 = linked_list_idx(ll, 1);
  void *ret2 = linked_list_idx(ll, 2);
  void *ret3 = linked_list_idx(ll, 3);

  cr_expect_not_null(ret0);
  cr_expect_not_null(ret1);
  cr_expect_not_null(ret2);
  cr_expect_null(ret3);

  cr_expect(item == ret0, "Return value is correct.");
  cr_expect(item2 == ret1, "Return value is correct.");
  cr_expect(item3 == ret2, "Return value is correct.");
}
