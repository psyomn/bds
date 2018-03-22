#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

struct bds_bitvec;

struct bds_bitvec* bds_bitvec_new(size_t cap);
void bds_bitvec_free(struct bds_bitvec* bitvec);
bool bds_bitvec_insert(struct bds_bitvec* bitvec, uint64_t val);
bool bds_bitvec_delete(struct bds_bitvec* bitvec, uint64_t val);
bool bds_bitvec_exists(struct bds_bitvec* bitvec, uint64_t val);
