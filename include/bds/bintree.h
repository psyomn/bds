#pragma once

#include <stdint.h>

#include <bds/common.h>

struct bds_bintree;

struct bds_bintree* bds_bintree_new();
void bds_bintree_free(struct bds_bintree* tree);
void bds_bintree_set_data(struct bds_bintree* tree, uint64_t data);
void bds_bintree_set_left(struct bds_bintree* tree, struct bds_bintree* left);
void bds_bintree_set_right(struct bds_bintree* tree, struct bds_bintree* right);
void bds_bintree_insert(struct bds_bintree* tree, uint64_t data);
struct option bds_bintree_search(struct bds_bintree* tree, uint64_t key);
