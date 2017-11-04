#include <bds/darray.h>
#include <stdio.h>

int main(void)
{
  struct bds_darray* arr = bds_darray_new(6);
  const size_t CAUSE_RESIZE = 20;

  fprintf(stdout, "start capacity %zu\n", bds_darray_capacity(arr));

  for (size_t x = 0; x < CAUSE_RESIZE; ++x)
    bds_darray_add(arr, (uint64_t) x);

  const size_t newcap = bds_darray_capacity(arr);
  fprintf(stdout, "resiz capacity %zu\n", newcap);

  for (size_t x = 0; x < newcap; ++x)
    fprintf(stdout, "%zu, ", bds_darray_get(arr, x));

  fprintf(stdout, "\n");

  bds_darray_free(arr);
  return 0;
}
