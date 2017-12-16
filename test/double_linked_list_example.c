#include <bds/double_linked_list.h>
#include <bds/test.h>

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

int main(void)
{
  BDS_TEST("test simple double linked list", {
      struct bds_double_linked_list* dlist = bds_double_linked_list_new();
      struct bds_double_linked_list_node* to_remove = NULL;

      assert(bds_double_linked_list_add_head(dlist, 1));
      assert(bds_double_linked_list_add_tail(dlist, 2));
      assert((to_remove = bds_double_linked_list_add_head(dlist, 3)));
      assert(bds_double_linked_list_add_tail(dlist, 4));

      const size_t prev_size = bds_double_linked_list_size(dlist);
      bds_double_linked_list_remove(dlist, to_remove);
      assert(bds_double_linked_list_size(dlist) == prev_size - 1);

      bds_double_linked_list_free(dlist);
    });

  return 0;
}
