#pragma once

#include <bds/common.h>
#include <unistd.h>
#include <stdint.h>

struct bds_darray;

struct bds_darray* bds_darray_new(size_t capacity);
void bds_darray_free(struct bds_darray* arr);
int bds_darray_add(struct bds_darray* arr, uint64_t data);
uint64_t bds_darray_get(struct bds_darray* arr, size_t index);
size_t bds_darray_capacity(struct bds_darray* arr);
void bds_darray_sort(struct bds_darray* arr);
struct option bds_darray_linear_search(struct bds_darray* arr, uint64_t item);
