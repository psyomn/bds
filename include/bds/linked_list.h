#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

struct bds_linked_list;

enum bds_linked_list_status {
  bds_linked_list_success,
  bds_linked_list_fail,
  bds_linked_list_not_found
};

struct bds_linked_list* bds_linked_list_new();
void bds_linked_list_free(struct bds_linked_list* list);
enum bds_linked_list_status bds_linked_list_add(struct bds_linked_list* list, uint64_t e);
size_t bds_linked_list_size(struct bds_linked_list* list);
uint64_t bds_linked_list_head_value(struct bds_linked_list* list);
void bds_linked_list_head_chop(struct bds_linked_list* list);
