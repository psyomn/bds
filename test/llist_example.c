#include <bds/linked_list.h>
#include <bds/test.h>
#include <stdio.h>
#include <assert.h>

int delete_from_empty_list(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();
  assert(0 == bds_linked_list_delete(llist, 1));
  assert(0 == bds_linked_list_delete(llist, 1));
  bds_linked_list_free(llist);
  return 0;
}

int common_example(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();

  bds_linked_list_add(llist, 1);
  bds_linked_list_add(llist, 2);
  bds_linked_list_add(llist, 3);

  const size_t size_after_add = bds_linked_list_size(llist);
  assert(size_after_add == 3);
  assert(bds_linked_list_head_value(llist) == 1);

  bds_linked_list_head_chop(llist);
  const size_t size_after_chop = bds_linked_list_size(llist);
  assert(size_after_chop == 2);
  assert(bds_linked_list_head_value(llist) == 2);

  bds_linked_list_head_chop(llist);
  bds_linked_list_head_chop(llist);
  const size_t ultimate_karate_chop = bds_linked_list_size(llist);
  assert(ultimate_karate_chop == 0);

  bds_linked_list_free(llist);

  return 0;
}

int add_20_elements(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();
  const size_t max_size = 20;

  for (size_t x = 0; x < max_size; ++x) {
    bds_linked_list_add(llist, x);
  }

  for (size_t x = 0; x < max_size; ++x) {
    const uint64_t value = bds_linked_list_head_value(llist);
    bds_linked_list_head_chop(llist);
    assert(value == x);
  }

  bds_linked_list_free(llist);

  return 0;
}

int add_5_elements_delete_2(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();

  for (size_t x = 0; x < 5; ++x)
    bds_linked_list_add(llist, x);

  assert(5 == bds_linked_list_size(llist));

  assert(1 == bds_linked_list_delete(llist, 1));
  assert(4 == bds_linked_list_size(llist));

  assert(1 == bds_linked_list_delete(llist, 2));
  assert(3 == bds_linked_list_size(llist));

  bds_linked_list_free(llist);

  return 0;
}

int add_3_same_elements_delete_only_one(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();
  bds_linked_list_add(llist, 1);
  bds_linked_list_add(llist, 1);
  bds_linked_list_add(llist, 1);
  assert(3 == bds_linked_list_size(llist));
  bds_linked_list_delete(llist, 1);

  assert(2 == bds_linked_list_size(llist));
  assert(1 == bds_linked_list_head_value(llist));
  assert(1 == bds_linked_list_tail_value(llist));
  bds_linked_list_free(llist);

  return 0;
}

int add_3_different_elements_delete_beginning(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();
  bds_linked_list_add(llist, 1);
  bds_linked_list_add(llist, 2);
  bds_linked_list_add(llist, 3);
  assert(3 == bds_linked_list_size(llist));
  bds_linked_list_delete(llist, 1);

  assert(2 == bds_linked_list_size(llist));
  assert(2 == bds_linked_list_head_value(llist));
  assert(3 == bds_linked_list_tail_value(llist));
  bds_linked_list_free(llist);

  return 0;
}

int add_3_different_elements_delete_middle(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();
  bds_linked_list_add(llist, 1);
  bds_linked_list_add(llist, 2);
  bds_linked_list_add(llist, 3);
  assert(3 == bds_linked_list_size(llist));
  bds_linked_list_delete(llist, 2);

  assert(2 == bds_linked_list_size(llist));
  assert(1 == bds_linked_list_head_value(llist));
  assert(3 == bds_linked_list_tail_value(llist));
  bds_linked_list_free(llist);

  return 0;
}

int add_3_different_elements_delete_tail(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();
  bds_linked_list_add(llist, 1);
  bds_linked_list_add(llist, 2);
  bds_linked_list_add(llist, 3);
  assert(3 == bds_linked_list_size(llist));
  bds_linked_list_delete(llist, 3);

  assert(2 == bds_linked_list_size(llist));
  assert(1 == bds_linked_list_head_value(llist));
  assert(2 == bds_linked_list_tail_value(llist));
  bds_linked_list_free(llist);

  return 0;
}

int add_1_element_delete_3(void **data)
{
  (void) data;
  struct bds_linked_list* llist = bds_linked_list_new();

  bds_linked_list_add(llist, 1);
  assert(1 == bds_linked_list_size(llist));
  assert(1 == bds_linked_list_delete(llist, 1));
  assert(0 == bds_linked_list_size(llist));
  assert(0 == bds_linked_list_delete(llist, 1));
  assert(0 == bds_linked_list_size(llist));
  assert(0 == bds_linked_list_delete(llist, 1));
  assert(0 == bds_linked_list_size(llist));

  bds_linked_list_free(llist);

  return 0;
}

int main(void) {
  bds_test("delete from empty list", delete_from_empty_list, NULL);
  bds_test("common example", common_example, NULL);
  bds_test("add 20 elements", add_20_elements, NULL);
  bds_test("add 5 elements delete 2", add_5_elements_delete_2, NULL);
  bds_test("add 3 same elements delete only one", add_3_same_elements_delete_only_one, NULL);
  bds_test("add 3 different elements delete beginning", add_3_different_elements_delete_beginning, NULL);
  bds_test("add 3 different elements delete middle", add_3_different_elements_delete_middle, NULL);
  bds_test("add 3 different elements delete tail", add_3_different_elements_delete_tail, NULL);
  bds_test("add 1 element delete 3", add_1_element_delete_3, NULL);
  return 0;
}
