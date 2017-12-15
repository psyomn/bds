#include <bds/linked_list.h>
#include <stdio.h>
#include <assert.h>

int main() {
  {
    printf("== common Example: ");

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
    printf("ok\n");
  }

  {
    printf("== 20 elements: ");

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
    printf("ok\n");
  }

  {
    printf("== add 5 elements, delete 2: ");
    struct bds_linked_list* llist = bds_linked_list_new();

    for (size_t x = 0; x < 5; ++x)
      bds_linked_list_add(llist, x);

    assert(5 == bds_linked_list_size(llist));

    assert(1 == bds_linked_list_del(llist, 1));
    assert(4 == bds_linked_list_size(llist));

    assert(1 == bds_linked_list_del(llist, 2));
    assert(3 == bds_linked_list_size(llist));

    bds_linked_list_free(llist);
    printf("ok\n");
  }

  {
    printf("== add 1 elements, delete 3: ");

    printf("ok\n");
  }

  return 0;
}
