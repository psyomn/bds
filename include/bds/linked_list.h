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
enum bds_linked_list_status bds_linked_list_add(struct bds_linked_list* list, void* e);
size_t bds_linked_list_size(struct bds_linked_list* list);
enum bds_linked_list_status bds_linked_list_insert_before(struct bds_linked_list* target, struct bds_linked_list* new);
enum bds_linked_list_status bds_linked_list_insert_after(struct bds_linked_list* target, struct bds_linked_list* new);
enum bds_linked_list_status bds_linked_list_remove_before(struct bds_linked_list* target);
enum bds_linked_list_status bds_linked_list_remove_after(struct bds_linked_list* target);


