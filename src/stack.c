#include <bds/stack.h>

#include <stdlib.h>
#include <assert.h>

struct node
{
  uint64_t element;
  struct node* next;
};

struct bds_stack
{
  struct node* top;
  size_t len;
};

struct bds_stack* bds_stack_new()
{
  struct bds_stack* new = calloc(1, sizeof(*new));
  return new;
}

void bds_stack_free(struct bds_stack* stack)
{
  assert(stack);
  struct node* it = stack->top;

  while (it)
  {
    struct node *next = it->next;
    free(it);
    it = next;
  }

  free(stack);
}

int bds_stack_push(struct bds_stack* stack, uint64_t element)
{
  assert(stack);
  struct node* node = calloc(1, sizeof(*node));

  if (!node) return 1;

  node->element = element;
  node->next = stack->top;
  stack->top = node;
  stack->len++;

  return 0;
}

uint64_t bds_stack_pop(struct bds_stack* stack)
{
  assert(stack && stack->len);

  uint64_t ret = stack->top->element;

  struct node* prev = stack->top;

  stack->top = stack->top->next;
  stack->len--;

  free(prev);

  return ret;
}

uint64_t bds_stack_peek(struct bds_stack* stack)
{
  assert(stack && stack->len);
  return stack->top->element;
}

size_t bds_stack_len(struct bds_stack* stack)
{
  return stack->len;
}
