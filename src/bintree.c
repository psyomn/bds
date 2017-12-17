#include <bds/bintree.h>
#include <bds/linked_list.h>

#include <stdlib.h>
#include <assert.h>

struct bds_bintree
{
  uint64_t data;
  struct bds_bintree* left;
  struct bds_bintree* right;
};

struct bds_bintree* bds_bintree_new(uint64_t data)
{
  struct bds_bintree* tree = calloc(1, sizeof(struct bds_bintree));
  tree->data = data;
  return tree;
}

#include <stdio.h>
void bds_bintree_free(struct bds_bintree* tree)
{
  assert(tree);
  struct bds_linked_list* list = bds_linked_list_new();
  struct bds_bintree* curr = tree;

  bds_linked_list_add(list, (uint64_t) tree);

  while (bds_linked_list_size(list) != 0) {
    curr = (struct bds_bintree*) bds_linked_list_head_value(list);
    if (curr->left)  bds_linked_list_add(list, (uint64_t) curr->left);
    if (curr->right) bds_linked_list_add(list, (uint64_t) curr->right);
    bds_linked_list_delete(list, (uint64_t) curr);
    free(curr);
  }

  bds_linked_list_free(list);
}

void bds_bintree_set_data(struct bds_bintree* tree, uint64_t data)
{
  assert(tree && data);
  tree->data = data;
}

void bds_bintree_insert(struct bds_bintree* tree, uint64_t data)
{
  assert(tree);
  struct bds_bintree* curr = tree;

  while (1) {
    if (data > curr->data) {
      if (curr->right) curr = curr->right;
      else {
        struct bds_bintree* new_node = bds_bintree_new(data);
        curr->right = new_node;
        return;
      }
    }
    else {
      if (curr->left) curr = curr->left;
      else {
        struct bds_bintree* new_node = bds_bintree_new(data);
        curr->left = new_node;
        return;
      }
    }
  }
}

void bds_bintree_set_left(struct bds_bintree* tree, struct bds_bintree* left)
{
  assert(tree && left);
  tree->left = left;
}

void bds_bintree_set_right(struct bds_bintree* tree, struct bds_bintree* right)
{
  assert(tree && right);
  tree->right = right;
}
