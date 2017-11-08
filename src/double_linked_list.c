#include <bds/double_linked_list.h>

#include <stdlib.h>
#include <assert.h>

struct bds_double_linked_list_node
{
  struct bds_double_linked_list_node* prev;
  struct bds_double_linked_list_node* next;
  uint64_t data;
};

struct bds_double_linked_list
{
  struct bds_double_linked_list_node* first;
  struct bds_double_linked_list_node* last;
  size_t size;
};

struct bds_double_linked_list* bds_double_linked_list_new()
{
  struct bds_double_linked_list* dlist = calloc(1, sizeof(struct bds_double_linked_list));
  return dlist;
}

void bds_double_linked_list_free(struct bds_double_linked_list* dlist)
{
  assert(dlist);
  struct bds_double_linked_list_node* curr = dlist->first;

  while (curr)
  {
    struct bds_double_linked_list_node* tmp = curr->next;
    free(curr);
    curr = tmp;
  }

  free(dlist);
}

struct bds_double_linked_list_node*
bds_double_linked_list_add_head(struct bds_double_linked_list* dlist, uint64_t data)
{
  assert(dlist);
  struct bds_double_linked_list_node* node = calloc(1, sizeof(struct bds_double_linked_list_node));

  if (!node) return NULL;

  node->prev = NULL;
  node->next = dlist->first;
  node->data = data;
  if (dlist->first) dlist->first->prev = node;
  else dlist->first = dlist->last = node;
  dlist->first = node;
  dlist->size++;

  return node;
}

struct bds_double_linked_list_node*
bds_double_linked_list_add_tail(struct bds_double_linked_list* dlist, uint64_t data)
{
  assert(dlist);
  struct bds_double_linked_list_node* node = calloc(1, sizeof(struct bds_double_linked_list_node));

  if (!node) return NULL;

  node->next = NULL;
  node->data = data;
  if (dlist->last) dlist->last->next = node;
  else dlist->first = dlist->last = node;
  node->prev = dlist->last;
  dlist->last = node;
  dlist->size++;

  return node;
}

int bds_double_linked_list_remove(struct bds_double_linked_list* dlist,
                                  struct bds_double_linked_list_node* node)
{
  assert(dlist && node);

  struct bds_double_linked_list_node* a = node->prev;
  struct bds_double_linked_list_node* b = node;
  struct bds_double_linked_list_node* c = node->next;

  if (node->prev == NULL && node->next == NULL) goto one_element;
  if (node->prev && node->next == NULL) goto tail;
  if (node->prev == NULL && node->next) goto head;
  else goto common;

 one_element:
  free(node);
  dlist->first = dlist->last = NULL;
  dlist->size = 0;
  return 0;

 head:
  dlist->first = node->next;
  dlist->first->prev = NULL;
  dlist->size--;
  free(node);
  return 0;

 tail:
  dlist->last = node->prev;
  dlist->last->next = NULL;
  dlist->size--;
  free(node);
  return 0;

 common:
  a->next = c;
  c->prev = a;
  dlist->size--;
  free(b);
  return 0;
}

size_t bds_double_linked_list_size(struct bds_double_linked_list* dlist)
{
  return dlist->size;
}
