#pragma once

#include <stdint.h>
#include <unistd.h>

struct bds_queue;

size_t bds_queue_len(const struct bds_queue* queue);
uint64_t bds_queue_deq(struct bds_queue* queue);
void bds_queue_enq(struct bds_queue* queue, uint64_t element);
struct bds_queue* bds_queue_new();
void bds_queue_free(struct bds_queue* queue);
