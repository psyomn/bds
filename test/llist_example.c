#include <bds/linked_list.h>
#include <stdio.h>
#include <assert.h>

int main() {
  {
    printf("== Common Example==\n");

    struct bds_linked_list* llist = bds_linked_list_new();

    bds_linked_list_add(llist, 1);
    bds_linked_list_add(llist, 2);
    bds_linked_list_add(llist, 3);

    const size_t size_after_add = bds_linked_list_size(llist);
    assert(size_after_add == 3);

    printf("linked list capacity: %zu\n", size_after_add);
    printf("value of head: %zu\n", bds_linked_list_head_value(llist));

    bds_linked_list_head_chop(llist);
    const size_t size_after_chop = bds_linked_list_size(llist);
    printf("linked list size after head chop: %zu\n", size_after_chop);
    printf("value of new head after chop: %zu\n", bds_linked_list_head_value(llist));

    bds_linked_list_head_chop(llist);
    bds_linked_list_head_chop(llist);
    const size_t ultimate_karate_chop = bds_linked_list_size(llist);
    printf("linked list size after all chop: %zu\n", ultimate_karate_chop);

    bds_linked_list_free(llist);

    printf("== end common example ==\n");
  }

  {
    printf("== 20 elements ==\n");

    struct bds_linked_list* llist = bds_linked_list_new();
    const size_t max_size = 20;

    for (size_t x = 0; x < max_size; ++x) {
      bds_linked_list_add(llist, x);
    }

    for (size_t x = 0; x < max_size; ++x) {
      const uint64_t value = bds_linked_list_head_value(llist);
      bds_linked_list_head_chop(llist);
      printf("%zu, ", value);
    }
    printf("\n");

    bds_linked_list_free(llist);
    printf("== end 20 elements ==\n");
  }

  return 0;
}
