#pragma once

#include <stdint.h>
#include <stdlib.h>

struct bds_double_linked_list;
struct bds_double_linked_list_node;

struct bds_double_linked_list* bds_double_linked_list_new();

void bds_double_linked_list_free(struct bds_double_linked_list* dlist);

struct bds_double_linked_list_node*
bds_double_linked_list_add_head(struct bds_double_linked_list* dlist, uint64_t data);

struct bds_double_linked_list_node*
bds_double_linked_list_add_tail(struct bds_double_linked_list* dlist, uint64_t data);

int bds_double_linked_list_remove(struct bds_double_linked_list* dlist,
                                  struct bds_double_linked_list_node* node);

size_t bds_double_linked_list_size(struct bds_double_linked_list* dlist);
