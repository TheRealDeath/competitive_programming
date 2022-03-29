from numpy import matrix
def fibn(n):
	h = False
	if n < 0 and abs(n)%2 == 0:
		h = True
	n = abs(n)
	bin_of_n = bin(n)[2:]
	f = [0, 1]
	for b in bin_of_n:
		f2i1 = f[1]**2 + f[0]**2
		f2i = f[0]*(2*f[1]-f[0])
		if b == '0':
			f[0], f[1] = f2i, f2i1
		else:
			f[0], f[1] = f2i1, f2i1+f2i
	return f[0] if not h else eval('-'+str(f[0])+'-0')
#below: matrix exponentiation. above: fast doubling
def fib(n):
  return (matrix('0 1; 1 1' if n >= 0 else '-1 1; 1 0', object) ** abs(n))[0, 1]