def modFact(n, p):
  if n >= p:
    return 0   
  result = 1
  for i in range(1, n + 1):
    result = (result * i) % p
 
  return result
#above: slower method but shorter. Below: faster method longer.
def largestPower(n, p):
	x = 0
	while (n):
		n //= p
		x += n
	return x
def power( x, y, p):
	res = 1
	x = x % p
	while (y > 0):
		if (y & 1):
			res = (res * x) % p
		y = y >> 1
		x = (x * x) % p
	return res
def _modFact( n, p) :
  if (n >= p) :
    return 0
  res = 1
  isPrime = [1] * (n + 1)
  i = 2
  while(i * i <= n):
    if (isPrime[i]):
      for j in range(2 * i, n, i) :
        isPrime[j] = 0
      i += 1
  for i in range(2, n):
    if (isPrime[i]) :
      k = largestPower(n, i)
      res = (res * power(i, k, p)) % p
  return res