#Contains algorithms for competitive programming
#Fast up to 15 million!!!!!!!!!!!!
def Sieve(n) : 
	primes = [2, 3] 
	lim, tog = n // 3, False 
	composite = [False for i in range(lim)] 
	d1 = 8; d2 = 8; p1 = 3; p2 = 7; s = 7; s2 = 3; m = -1 
	while s < lim :       
		m += 1                  
		if not composite[m] :    
			inc = p1 + p2 
			for k in range(s,      lim, inc) : composite[k] = True 
			for k in range(s + s2, lim, inc) : composite[k] = True 
			tog = not tog 
			if tog: s += d2; d1 += 16; p1 += 2; p2 += 2; s2 = p2 
			else:   s += d1; d2 +=  8; p1 += 2; p2 += 6; s2 = p1 
	k, p, tog = 0, 5, False 
	while p <= n : 
		if not composite[k] : primes.append(p) 
		k += 1; 
		tog = not tog 
		p += 2 if tog else 4 
	return primes 
print(Sieve(100))