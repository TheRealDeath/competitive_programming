def SieveOfEratosthenes(n):
	prime = [True] * (n+1)
	p = 2
	while(p ** 2 <= n):
		if (prime[p] == True):
			for i in range(p ** 2, n + 1, p):
				prime[i] = False
		p += 1
	myList = []
	for p in range(2, n):
		if prime[p]:
				myList.append(p)
	return myList
#fastest method for calculating primes under n