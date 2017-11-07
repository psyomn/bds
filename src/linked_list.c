#include <bds/linked_list.h>

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

struct _node
{
  uint64_t data;
  struct _node* next;
};

struct bds_linked_list
{
  size_t size;
  struct _node* head;
  struct _node* tail;
};

struct bds_linked_list* bds_linked_list_new()
{
  struct bds_linked_list *list = calloc(1, sizeof(struct bds_linked_list));
  return list;
}

void bds_linked_list_free(struct bds_linked_list* list)
{
  assert(list);
  struct _node* curr = list->head;
  struct _node* next = NULL;

  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  free(list);
}

enum bds_linked_list_status
bds_linked_list_add(struct bds_linked_list* list, uint64_t e)
{
  assert(list);
  struct _node* new = calloc(1, sizeof(struct _node));
  new->data = e;

  if (bds_linked_list_size(list) == 0) goto new_list;
  else goto common;

 new_list:
  list->size++;
  list->head = new;
  list->tail = new;
  return bds_linked_list_success;

 common:
  list->size++;
  list->tail->next = new;
  list->tail = new;
  return bds_linked_list_success;
}

size_t bds_linked_list_size(struct bds_linked_list* list)
{
  return list->size;
}

uint64_t bds_linked_list_head_value(struct bds_linked_list* list)
{
  assert(list && list->head);
  return list->head->data;
}

uint64_t bds_linked_list_tail_value(struct bds_linked_list* list)
{
  assert(list && list->tail);
  return list->tail->data;
}

void bds_linked_list_head_chop(struct bds_linked_list* list)
{
  assert(list && list->head);
  struct _node* head = list->head;
  struct _node* prev_head = head;
  list->head = head->next;
  free(prev_head);
  list->size--;
}

uint8_t bds_linked_list_delete(struct bds_linked_list* list, uint64_t element)
{
  assert(list);
  struct _node* prev = NULL;
  struct _node* curr = list->head;

  while (curr) {
    if (curr->data == element) {
      if (prev)               prev->next = curr->next;
      if (curr == list->tail) list->tail = prev;
      if (curr == list->head) list->head = curr->next;
      free(curr);
      list->size--;
      return 1;
    }
    prev = curr;
    curr = curr->next;
  }

  return 0;
}
