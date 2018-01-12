#include <bds/test.h>
#include <bds/bintree.h>
#include <bds/rand.h>

#include <stdio.h>
#include <assert.h>

int manual_intervention_test(void **data)
{
  (void) data;
  struct bds_bintree* bintree = bds_bintree_new(1);
  struct bds_bintree* left = bds_bintree_new(2);
  struct bds_bintree* right = bds_bintree_new(3);
  struct bds_bintree* r1 = bds_bintree_new(4);
  struct bds_bintree* r2 = bds_bintree_new(5);

  bds_bintree_set_data(bintree, 1);
  bds_bintree_set_data(left, 2);
  bds_bintree_set_data(right, 3);
  bds_bintree_set_data(r1, 4);
  bds_bintree_set_data(r2, 5);

  bds_bintree_set_left(bintree, left);
  bds_bintree_set_right(bintree, right);
  bds_bintree_set_left(right, r1);
  bds_bintree_set_right(right, r2);

  bds_bintree_free(bintree);
  return 0;
}

int insert_test(void **data)
{
  (void) data;
  struct bds_bintree* bintree = bds_bintree_new(30);
  bds_bintree_insert(bintree, 1);
  bds_bintree_insert(bintree, 40);
  bds_bintree_insert(bintree, 2);
  bds_bintree_free(bintree);
  return 0;
}

int search_test(void **data)
{
  (void) data;
  struct bds_bintree* bintree = bds_bintree_new(30);
  struct bds_lcg* lcg  = bds_lcg_lehmer();
  uint64_t key_to_find = 0;

  for (size_t i = 0; i < 100; ++i) {
    const uint64_t num = bds_lcg_next(lcg);
    bds_bintree_insert(bintree, num);
    if (i == 50) key_to_find = num;
  }

  const struct option result = bds_bintree_search(bintree, key_to_find);
  assert(result.present == 1);
  assert(result.value == 0);

  const struct option unfound = bds_bintree_search(bintree, 0);
  assert(unfound.present == 0);

  bds_bintree_free(bintree);
  bds_lcg_free(lcg);
  return 0;
}

int main(void)
{
  bds_test("manual node insert test", manual_intervention_test, NULL);
  bds_test("insert test", insert_test, NULL);
  bds_test("test simple search", search_test, NULL);
  return 0;
}
