#include <bds/test.h>
#include <bds/bitvec.h>

#include <assert.h>

int simple_test(void **data)
{
  (void) data;
  struct bds_bitvec* bv = bds_bitvec_new(1000);

  for (size_t i = 0; i < 10; ++i)
    bds_bitvec_insert(bv, i);

  for (size_t i = 400; i < 900; ++i)
    assert(!bds_bitvec_exists(bv, i));

  for (size_t i = 0; i < 10; ++i)
    assert(bds_bitvec_exists(bv, i));

  bds_bitvec_free(bv);
  return 0;
}

int main(int argc, char* argv[])
{
  (void) argc, (void) argv;
  bds_test("simple test", simple_test, NULL);
  return 0;
}
