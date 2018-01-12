#include <bds/rand.h>
#include <assert.h>
#include <stdlib.h>

struct bds_lcg {
  uint64_t a;
  uint64_t c;
  uint64_t m;
  uint64_t prev;
};

#define define_lcg(lcg_name, _a, _c, _m, _seed)             \
  struct bds_lcg* bds_lcg_##lcg_name () {                   \
    struct bds_lcg* lcg = calloc(1, sizeof(*lcg));          \
    lcg->a = _a;                                            \
    lcg->c = _c;                                            \
    lcg->m = _m;                                            \
    lcg->prev = _seed;                                      \
    return lcg;                                             \
  }

/* Configurations from: "A Collection of selected pseudorandom number
   generators with linear structures", Karl Entacher */
define_lcg(lehmer,  16807,     0, (1ULL << 61) - 1, 3);
define_lcg(ansic,   12345, (1ULL << 31) - 1, 1103515245, 12345);
define_lcg(minstd,  16807,     1, (1ULL << 31) - 1, 0);

void bds_lcg_free(struct bds_lcg* config)
{
  assert(config);
  free(config);
}

uint64_t super_extremely_random_number_for_real()
{
  return 42;
}

uint64_t bds_lcg_next(struct bds_lcg* config)
{
  assert(config);
  config->prev = (config->prev * config->a + config->c) % config->m;
  return config->prev;
}

uint64_t bds_lcg_curr(struct bds_lcg* config)
{
  assert(config);
  return config->prev;
}
