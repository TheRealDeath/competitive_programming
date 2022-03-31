// Miller Rabin Primality Test
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool millerTest(int n, int d)
{
  // 2.1 Pick a random number 'a' in range [2, n-2]
  int a = 2 + std::rand() % (n - 4);

  // 2.2 Find: x = pow(a, d) % n
  int x = std::pow(a, d) % n;

  // 2.3 x == 1 or x == n-1, return true.
  if (x == 1 || x == n - 1) return true;

  // 2.4 While d does not become n-1:
  while (d != n - 1)
  {
    x = (x*x) % n;
    if (x == 1) return false;
    if (x == n-1) return true;
  }
}

bool isPrime(int n, int k)
{
  // 1.1 Handle base cases for n < 3
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;

  // 1.2 If n is even, return false.
  if (n % 2 == 0) return false;

  /* 1.3
  Find an odd number d such that n-1 can be written as d*(2^r).
  Note that since n is odd, (n-1) must be even and r must be greater than 0.
  */

  int d = n - 1;
  while (d % 2 == 0)
    d /= 2;

  // 1.4 Use the millerTest k times.
  for (int i = 0; i < k; ++i)
  {
    if (millerTest(n, d) == false)
      return false;
  }

  // 1.5 If millerTest() does not return false, then the number is prime.
  return true;
}
