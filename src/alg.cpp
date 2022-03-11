// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (0 == n) {
    return 1;
  }
  if (1 == n) {
    return value;
  } else {
    return value*pown(value, n-1);
  }
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    return n*fact(n-1);
  }
}

double calcItem(double x, uint16_t n) {
  double a = pown(x, n) / fact(n);
    return a;
}

double expn(double x, uint16_t count) {
  if ((x == 0) || (count == 0))
    return 1;
  return calcItem(x, count) + expn(x, count - 1);
}

double sinn(double x, uint16_t count) {
  double p = 0;
for (int j = count; j > 0; j--) {
  p+=pown((-1), j - 1) * pown(x, 2 * j - 1) / fact(2*j-1);
  }
  return p;
}

double cosn(double x, uint16_t count) {
    double res = 1;
      for (int j = 2; j <= count; j++) {
         if (pown(-1, j - 1) == 1) {
            res += calcItem(x, (j * 2) - 2);
         } else {
            res -= calcItem(x, (j * 2) - 2);
         }
      }
      return res;
}
