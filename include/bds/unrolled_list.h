#pragma once

#include <stdlib.h>
#include <stdint.h>

struct bds_unrolled_list_node;
struct bds_unrolled_list;

struct bds_unrolled_list* bds_unrolled_list_new(size_t node_capacity);
void bds_unrolled_list_free(struct bds_unrolled_list* ulist);
void bds_unrolled_list_push_back(struct bds_unrolled_list* ulist, uint64_t data);
