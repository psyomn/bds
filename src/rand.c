#include <bds/rand.h>
#include <assert.h>
#include <stdlib.h>

struct bds_lcg {
  uint64_t a;
  uint64_t c;
  uint64_t m;
  uint64_t seed;
  uint64_t prev;
};

struct bds_lcg* bds_lcg_lehmer() {
  struct bds_lcg* lcg = calloc(1, sizeof(*lcg));
  lcg->a = 16807;
  lcg->c = 0;
  lcg->m = (1ULL << 61) - 1;
  lcg->seed = 3; // anything but the value of m
  lcg->prev = 3;
  return lcg;
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
