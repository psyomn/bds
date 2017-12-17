#include <bds/test.h>
#include <bds/bintree.h>
#include <stdio.h>

void manual_intervention_test()
{
  BDS_TEST("manual interventions test", {
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
    });
}

void insert_test()
{
  BDS_TEST("insert test", {
      struct bds_bintree* bintree = bds_bintree_new(30);
      bds_bintree_insert(bintree, 1);
      bds_bintree_insert(bintree, 40);
      bds_bintree_insert(bintree, 2);
      bds_bintree_free(bintree);
    });
}

int main(void)
{
  manual_intervention_test();
  insert_test();
  return 0;
}
