#pragma once

#include <stdint.h>

struct bds_lcg;

struct bds_lcg* bds_lcg_lehmer();
void bds_lcg_free(struct bds_lcg* config);
uint64_t bds_lcg_next(struct bds_lcg* config);
uint64_t bds_lcg_curr(struct bds_lcg* config);
uint64_t super_extremely_random_number_for_real();
