#include <bds/test.h>
#include <bds/rand.h>
#include <assert.h>

int test_lehmer_lcg(void **data)
{
  (void) data;
  struct bds_lcg* lehmer = bds_lcg_lehmer();
  const uint64_t rand_num = bds_lcg_next(lehmer);
  printf("%zu\n", rand_num);
  assert(rand_num != 0);
  const uint64_t rand_num2 = bds_lcg_next(lehmer);
  printf("%zu\n", rand_num2);
  assert(rand_num != rand_num2);
  return 0;
}

int main(void)
{
  bds_test("test simple lehmer generator", test_lehmer_lcg, NULL);
  return 0;
}
