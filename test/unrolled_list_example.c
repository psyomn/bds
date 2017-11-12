#include <bds/unrolled_list.h>

#include <stdio.h>

int main(void) {
  struct bds_unrolled_list* ulist = bds_unrolled_list_new(2 << 8);

  for (size_t x = 0; x < (2 << 10); ++x)
    bds_unrolled_list_push_back(ulist, x);

  bds_unrolled_list_free(ulist);
  return 0;
}
