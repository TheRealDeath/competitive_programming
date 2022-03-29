int modExp(int x, int y, int p)
{
	int res = 1;
	int x = x%p;
	if(x == 0) return 0;
	while(y > 0)
		if((y&1) == 1)
		{
			res = (res*x) % p;
			y >>= 1;
			x = (x*x) % p;
		}
	return res;
}