#pragma once

#include <stdio.h>
#include <time.h>
#include <stdio.h>

#define bds_test(l, fn, dt) _bds_test(__FILE__ ": " l, fn, dt)

void _bds_test(const char* label, int (*func)(void **data), void **data)
{
  printf("%s:", label);

  const clock_t start = clock();
  const time_t time_start = time(NULL);
  const int ret = func(data);
  const clock_t end = clock();
  const time_t time_end = time(NULL);
  const double elapsed = (end - start) /(double) CLOCKS_PER_SEC;
  const size_t elapsed_time = (time_end - time_start);

  fprintf(stdout, " %s [wc:%f][tm:%zu]\n", !ret ? "ok" : "fail", elapsed, elapsed_time);
}
