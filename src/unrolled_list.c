#include <bds/unrolled_list.h>

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

struct bds_unrolled_list_node
{
  struct bds_unrolled_list_node* next;
  struct bds_unrolled_list_node* prev;
  size_t index;
  uint64_t data[];
};

struct bds_unrolled_list
{
  size_t num_nodes;
  size_t node_capacity;
  struct bds_unrolled_list_node* head;
  struct bds_unrolled_list_node* tail;
};

struct bds_unrolled_list* bds_unrolled_list_new(size_t node_capacity)
{
  assert(node_capacity > 0);
  struct bds_unrolled_list* ulist = calloc(1, sizeof(struct bds_unrolled_list));
  ulist->node_capacity = node_capacity;
  return ulist;
}

static int node_is_full(struct bds_unrolled_list_node* node, size_t capacity)
{
  return (node->index + 1) == capacity;
}

static struct bds_unrolled_list_node* alloc_node(size_t capacity)
{
  return
    calloc(1, (sizeof(struct bds_unrolled_list_node)
               + (capacity * sizeof(uint64_t))));
}

void bds_unrolled_list_free(struct bds_unrolled_list* ulist)
{
  assert(ulist);

  struct bds_unrolled_list_node* curr = ulist->head;
  struct bds_unrolled_list_node* temp = NULL;

  while (curr)
  {
    temp = curr->next;
    free(curr);
    curr = temp;
  }

  free(ulist);
}

void bds_unrolled_list_push_back(struct bds_unrolled_list* ulist, uint64_t data)
{
  assert(ulist);
  if (ulist->tail == NULL && ulist->head == NULL) goto start_empty;
  if (node_is_full(ulist->tail, ulist->node_capacity)) goto alloc_new;
  else goto just_push_one;

 start_empty:
  {
    struct bds_unrolled_list_node* node = alloc_node(ulist->node_capacity);
    ulist->head = ulist->tail = node;
    ulist->tail->data[0] = data;
    ulist->tail->index++;
    ulist->num_nodes++;
    return;
  }

 alloc_new:
  {
    struct bds_unrolled_list_node* node = alloc_node(ulist->node_capacity);
    ulist->tail->next = node;
    node->prev = ulist->tail;
    ulist->tail = node;
    ulist->tail->data[0] = data;
    ulist->tail->index++;
    ulist->num_nodes++;
    return;
  }

 just_push_one:
  ulist->tail->data[ulist->tail->index] = data;
  ulist->tail->index++;
  return;
}

size_t bds_unrolled_list_num_nodes(struct bds_unrolled_list* ulist)
{
  assert(ulist);
  return ulist->num_nodes;
}

size_t bds_unrolled_list_tail_index(struct bds_unrolled_list* ulist)
{
  assert(ulist && ulist->tail);
  return ulist->tail->index;
}
