#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n)
{
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	int lim = n/3;
	bool tog = false;
	bool composite[lim];
	for(int i = 0;i<=lim;i++)
		composite[i] = false;
	int d1 = 8, d2 = 8, p1 = 3, p2 = 7, s = 7, s2 = 3, m = -1;
	while(s < lim)
	{
		m++;
		if(!composite[m])
		{
			for(int i = s;i<lim;i+=(p2+p1)) composite[i] = true;
			for(int i = s+s2;i<lim;i+=(p2+p1)) composite[i] = true;
			tog = !tog;
			if(tog)
			{
				s += d2;
				d1 += 16;
				p1 += 2;
				p2 += 2;
				s2 = p2;
			}
			else
			{
				s += d1;
				d2 += 8;
				p1 += 2;
				p2 += 6;
				s2 = p1;
			}
		}
	}
	int k = 0;
	int p = 5;
	tog = false;
	while(p <= n)
	{
		if(!composite[k]) primes.push_back(p);
		k += 1;
		tog = !tog;
		p += tog ? 2 : 4;
	}
	return primes;
}