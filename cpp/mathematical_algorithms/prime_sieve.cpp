#include <iostream>
#include <vector>
using namespace std;

vector<int> Sieve(int n)
{
	bool primes[n+1];
	for(int i = 0;i<n+1;i++)
		primes[i] = true;
	int p = 2;
	while(p * p <= n)
	{
		if(primes[p])
		for(int i = p*p;i<n+1;i+=p)
			primes[i] = false;
		p++;
	}
	vector<int> myList;
	for(int i = 2;i<n;i++)
		if(primes[i]) myList.push_back(i);
	return myList;
}