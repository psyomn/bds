#include <bds/linked_list.h>

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

struct _node
{
  void* data;
  struct _node* next;
};

struct bds_linked_list
{
  size_t size;
  struct _node* data;
  struct _node* tail;
};

struct bds_linked_list* bds_linked_list_new()
{
  struct bds_linked_list *list = malloc(sizeof(struct bds_linked_list));
  list->tail = NULL;
  return list;
}

void bds_linked_list_free(struct bds_linked_list* list)
{
  assert(list);
  struct _node* curr = list->data;
  struct _node* next = list->data->next;

  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }
}

enum bds_linked_list_status
bds_linked_list_add(struct bds_linked_list* list, void* e)
{
  assert(list != NULL);
  struct _node* new = malloc(sizeof(struct _node));
  
  list->tail = new;
  new->data = e;

  return bds_linked_list_success;
}

enum bds_linked_list_status
bds_linked_list_insert_before(struct bds_linked_list* target, struct bds_linked_list* new)
{
  (void) target;
  (void) new;
  return bds_linked_list_success;
}

enum bds_linked_list_status
bds_linked_list_insert_after(struct bds_linked_list* target, struct bds_linked_list* new)
{
  (void) target;
  (void) new;
  return bds_linked_list_success;
}

enum bds_linked_list_status
bds_linked_list_remove_before(struct bds_linked_list* target)
{
  (void) target;
  return bds_linked_list_success;
}

enum bds_linked_list_status
bds_linked_list_remove_after(struct bds_linked_list* target)
{
  (void) target;
  return bds_linked_list_success;
}

size_t bds_linked_list_size(struct bds_linked_list* list)
{
  return list->size;
}
