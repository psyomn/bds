#pragma once

#include <stdio.h>

#define BDS_TEST(label, expr)                                   \
  do {                                                          \
    printf("%s:%s# %s: ", __FILE__, __FUNCTION__, label);       \
    expr;                                                       \
    printf("ok\n");                                             \
  } while (0)
