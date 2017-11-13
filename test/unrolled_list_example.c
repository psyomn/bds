#include <bds/unrolled_list.h>

#include <stdio.h>
#include <assert.h>

#define LABEL_FUNC do { fprintf(stdout, "#### %s:%s\n", __FILE__, __FUNCTION__); } while (0)

void add_none()
{
  LABEL_FUNC;

  struct bds_unrolled_list* ulist = bds_unrolled_list_new(2 << 8);
  const size_t first_num_nodes = bds_unrolled_list_num_nodes(ulist);
  fprintf(stdout, "num nodes before: %zu\n", first_num_nodes);
  assert(first_num_nodes == 0);
  bds_unrolled_list_free(ulist);
}

void add_one()
{
  LABEL_FUNC;

  struct bds_unrolled_list* ulist = bds_unrolled_list_new(2 << 8);
  const size_t first_num_nodes = bds_unrolled_list_num_nodes(ulist);
  fprintf(stdout, "num nodes before: %zu\n", first_num_nodes);
  assert(first_num_nodes == 0);

  bds_unrolled_list_push_back(ulist, 1);
  const size_t add_two = bds_unrolled_list_num_nodes(ulist);
  fprintf(stdout, "num nodes after: %zu\n", add_two);
  assert(add_two == 1);

  bds_unrolled_list_free(ulist);
}

void mash_new_nodes()
{
  LABEL_FUNC;

  struct bds_unrolled_list* ulist = bds_unrolled_list_new(2 << 7);
  const size_t first_num_nodes = bds_unrolled_list_num_nodes(ulist);
  fprintf(stdout, "num nodes before: %zu\n", first_num_nodes);
  assert(first_num_nodes == 0);

  for (size_t x = 0; x < (2 << 7); ++x)
    bds_unrolled_list_push_back(ulist, x);

  const size_t num_nodes = bds_unrolled_list_num_nodes(ulist);
  fprintf(stdout, "num nodes after bruteforcing: %zu\n", num_nodes);
  assert(num_nodes == 2);

  bds_unrolled_list_free(ulist);
}

int main(void)
{
  add_none();
  add_one();
  mash_new_nodes();

  return 0;
}
