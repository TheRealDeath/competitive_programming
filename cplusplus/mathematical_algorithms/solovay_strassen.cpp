#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "binary_exponentiation.cpp"

int calculateJacobian(long long a, long long n)
{
  if (!a) return 0;
  int ans = 1;
  if a < 0
  {
    a = -a;
    if (n % 4 == 3)
    ans = -ans;
  }
  if (a == 1) return ans;
  while (a)
  {
    if (a < 0)
    {
      a = -a;
      if (n % 4 == 3)
        ans = -ans;
    }
    while (a % 2 == 0)
    {
      a = a / 2;
      if (n % 8 == 3 || n % 8 == 5)
        ans = -ans;
    }

    swap(a, n);

    if (a % 4 == 3 && n % 4 == 3)
      ans = -ans;
    if (a > n / 2)
      a = a - n;
  }

  if (n == 1) return ans;
  return 0;

}

bool solovayStrassen(long long p, int iterations)
{
  if (p < 2) return false;
  if (p != 2 && p % 2 == 0) return false;

  for (int i = 0; i < iterations; i++)
  {
    long long a = 1 + rand() % (p - 1);
    long long jacobian = (p + calculateJacobian(a, p)) % p;
    long long mod = modulo_binpow(a, (p - 1) / 2, p);

    if (!jacobian || mod != jacobian) return false;
  }
  return true;
}