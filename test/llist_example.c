#include <bds/linked_list.h>
#include <stdio.h>

int main() {
  struct bds_linked_list* llist = bds_linked_list_new();

  bds_linked_list_add(llist, (void*) 12);
  bds_linked_list_add(llist, (void*) 13);
  bds_linked_list_add(llist, (void*) 14);

  printf("linked list capacity: %zu", bds_linked_list_size(llist));
  
  bds_linked_list_free(llist);

  return 0;
}
