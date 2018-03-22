#include <bds/bitvec.h>
#include <stdlib.h>
#include <assert.h>

struct bds_bitvec
{
  size_t cap;
  uint64_t data[];
};

struct bds_bitvec* bds_bitvec_new(size_t cap)
{
  struct bds_bitvec* ret = calloc(1, sizeof(*ret) + cap * sizeof(ret->data[0]));
  return ret;
}

void bds_bitvec_free(struct bds_bitvec* bitvec)
{
  free(bitvec);
}

static inline void lookup(uint64_t val, size_t arr[static 2])
{
  const uint64_t div = val / 64;
  const uint64_t rem = val % 64;
  arr[0] = div;
  arr[1] = rem;
}

bool bds_bitvec_insert(struct bds_bitvec* bitvec, uint64_t val)
{
  assert(bitvec);
  size_t pos[2];
  lookup(val, pos);
  bitvec->data[pos[0]] |= (1ULL << pos[1]);
  return true;
}

bool bds_bitvec_delete(struct bds_bitvec* bitvec, uint64_t val)
{
  assert(bitvec);
  size_t pos[2];
  lookup(val, pos);
  bitvec->data[pos[0]] &= ~(1ULL << pos[1]);
  return true;
}

bool bds_bitvec_exists(struct bds_bitvec* bitvec, uint64_t val)
{
  assert(bitvec);
  size_t pos[2];
  lookup(val, pos);
  return (bitvec->data[pos[0]] & (1ULL << pos[1])) >> pos[1];
}
