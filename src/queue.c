#include <bds/queue.h>

#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

struct bds_queue {
  struct node* first;
  struct node* last;
  size_t len;
};

struct node {
  uint64_t value;
  struct node* next;
};

size_t bds_queue_len(const struct bds_queue* queue)
{
  return queue->len;
}

uint64_t bds_queue_deq(struct bds_queue* queue)
{
  assert(queue);
  assert(queue->len);
  struct node* prev_first = queue->first;
  const uint64_t ret = queue->first->value;

  queue->first = queue->first->next;
  free(prev_first);
  queue->len--;

  return ret;
}

void bds_queue_enq(struct bds_queue* queue, uint64_t element)
{
  assert(queue);
  struct node* new = calloc(1, sizeof(*new));
  new->value = element;

  queue->len++;

  if (queue->last) goto non_empty;
  else goto empty;

 non_empty:
  queue->last->next = new;
  queue->last = new;
  return;

 empty:
  queue->last = new;
  queue->first = new;
  return;
}

struct bds_queue* bds_queue_new()
{
  struct bds_queue* new = calloc(1, sizeof(*new));
  return new;
}

void bds_queue_free(struct bds_queue* queue)
{
  assert(queue);
  struct node* it = queue->first;
  struct node* next = NULL;

  while (it) {
    next = it->next;
    free(it);
    it = next;
  }

  free(queue);
}
