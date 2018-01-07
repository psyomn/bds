#include <bds/test.h>
#include <bds/darray.h>
#include <stdio.h>
#include <assert.h>

int simple_test(void **data)
{
  (void) data;

  struct bds_darray* arr = bds_darray_new(6);
  const size_t CAUSE_RESIZE = 20;

  const size_t initial_cap = bds_darray_capacity(arr);

  for (size_t x = 0; x < CAUSE_RESIZE; ++x)
    bds_darray_add(arr, (uint64_t) x);

  const size_t new_cap = bds_darray_capacity(arr);
  assert(new_cap != initial_cap);
  assert(new_cap > initial_cap);

  bds_darray_free(arr);
  return 0;
}

int add_a_lot_test(void **data)
{
  (void) data;
  struct bds_darray* arr = bds_darray_new(10);
  const size_t num_elements = 10000000;
  const size_t init_cap = bds_darray_capacity(arr);

  for (size_t x = 0; x < num_elements; ++x) {
    bds_darray_add(arr, x);
  }

  const size_t new_cap = bds_darray_capacity(arr);
  assert(new_cap != init_cap);

  for (size_t x = 0; x < num_elements; ++x) {
    assert(x == bds_darray_get(arr, x));
  }

  bds_darray_free(arr);
  return 0;
}

int sort_test(void **data)
{
  (void) data;
  const uint64_t to_add[] = { 10, 4, 8, 5, 2, 3, 123 };
  const uint64_t expected[] = { 2, 3, 4, 5, 8, 10, 123 };
  const size_t num_elements = sizeof(to_add) / sizeof(to_add[0]);
  struct bds_darray* arr = bds_darray_new(32);

  for (size_t x = 0; x < num_elements; ++x)
    bds_darray_add(arr, to_add[x]);

  bds_darray_sort(arr);

  for (size_t x = 0; x < num_elements; ++x)
    assert(expected[x] == bds_darray_get(arr, x));

  bds_darray_free(arr);
  return 0;
}

int main(void)
{
  bds_test("simple test", simple_test, NULL);
  bds_test("add a lot test", add_a_lot_test, NULL);
  bds_test("sort test", sort_test, NULL);
  return 0;
}
