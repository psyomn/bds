#include <bds/test.h>
#include <bds/stack.h>

#include <assert.h>

int test_push_pop(void **data)
{
  (void) data;
  struct bds_stack* stack = bds_stack_new();

  bds_stack_push(stack, 1);
  bds_stack_push(stack, 2);
  bds_stack_push(stack, 3);
  bds_stack_push(stack, 4);
  bds_stack_push(stack, 5);

  assert(bds_stack_len(stack) == 5);
  assert(bds_stack_peek(stack) == 5);
  assert(bds_stack_pop(stack) == 5);
  assert(bds_stack_len(stack) == 4);
  assert(bds_stack_peek(stack) == 4);

  bds_stack_free(stack);

  return 0;
}

int test_big(void **data)
{
  (void) data;

  struct bds_stack* stack = bds_stack_new();

  for (size_t i = 0; i < 100000; ++i)
    bds_stack_push(stack, i);

  bds_stack_free(stack);
  return 0;
}

int main(void) {
  bds_test("test push pop", test_push_pop, NULL);
  bds_test("test big", test_big, NULL);
  return 0;
}
