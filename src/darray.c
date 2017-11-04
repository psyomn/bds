/* TODO: might not align well in memory if not in multiples of 2 */

#include <bds/darray.h>

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
