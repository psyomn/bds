#pragma once

#include <stdint.h>
#include <unistd.h>

struct bds_stack;

struct bds_stack* bds_stack_new();
void bds_stack_free(struct bds_stack* stack);
int bds_stack_push(struct bds_stack* stack, uint64_t element);
uint64_t bds_stack_pop(struct bds_stack* stack);
uint64_t bds_stack_peek(struct bds_stack* stack);
size_t bds_stack_len(struct bds_stack* stack);
