/* TODO: might not align well in memory if not in multiples of 2 */

#include <bds/darray.h>
#include <bds/common.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>

static const size_t _BDS_DARRAY_MIN_CAP = 5;

struct bds_darray
{
  size_t capacity;
  size_t current_index;
  uint64_t* data;
};

inline size_t calculate_capacity(size_t curr_cap)
{
  return curr_cap * 2;
}

inline size_t calculate_size(size_t capacity)
{
  return (capacity * sizeof(uint64_t));
}

struct bds_darray* bds_darray_new(size_t capacity)
{
  assert(capacity > _BDS_DARRAY_MIN_CAP);
  struct bds_darray* darray = calloc(1, sizeof(struct bds_darray));
  darray->capacity = capacity;
  darray->data = calloc(capacity, sizeof(darray->data[0]));
  return darray;
}

void bds_darray_free(struct bds_darray* arr)
{
  assert(arr);
  free(arr->data);
  free(arr);
}

int bds_darray_add(struct bds_darray* arr, uint64_t data)
{
  assert(arr);

  if (arr->current_index == arr->capacity) {
    const size_t newcap = calculate_capacity(arr->capacity);

    uint64_t* resized = realloc(arr->data, calculate_size(newcap));

    if (resized) {
      arr->data = resized;
      arr->capacity = newcap;
    }

    else goto fail_realloc;
  }

  arr->data[arr->current_index] = data;
  arr->current_index++;

  return 0;

 fail_realloc:
  fprintf(stderr, "problem reallocating darray\n");
  exit(-1);
}

uint64_t bds_darray_get(struct bds_darray* arr, size_t index)
{
  assert(arr);
  assert(index <= arr->capacity);
  return arr->data[index];
}

size_t bds_darray_capacity(struct bds_darray* arr)
{
  assert(arr);
  return arr->capacity;
}

static int cmp_arr(const void* e1, const void* e2)
{
  uint64_t x = *(uint64_t*) e1, y = *(uint64_t*) e2;
  if (x > y) return 1;
  if (x < y) return -1;
  return 0;
}

void bds_darray_sort(struct bds_darray* arr)
{
  assert(arr);

  qsort(
    arr->data,
    arr->current_index,
    sizeof(arr->data[0]),
    cmp_arr);
}

struct option bds_darray_linear_search(struct bds_darray* arr, uint64_t item)
{
  struct option found_values = {0};
  for (size_t x = 0; x < arr->current_index; ++x) {
    if (bds_darray_get(arr, x) == item) {
      found_values.present = 1;
      found_values.value = x;
    }
  }
  return found_values;
}
