import java.util.Arrays;
public class ModFact
{
	int modFact(int n, int p)
	{
		if(n >= p) return 0;
		int result = 1;
		for(int i = 1;i<n+1;i++)
			result = (result*i) % p;
		return result;
	}
	//above smaller slower, below larger faster
	int largestPower(int n, int p)
	{
		int x = 0;
		while(n > 0))
		{
			n /= p;
			x += n;
		}
	}
	int power(int x, int y, int p)
	{
		int res = 1;
		x = x % p;
		while(y > 0)
		{
			if(y%2 == 1)
				res = (res*x) % p;
			y >>= 1;
			x = (x*x) % p;
		}
		return res;
	}
	int modularFactorial(int n, int p)
	{
		if(n >= p) return 0;
		int res = 1;
		int[] isPrime = new int[n+1];
		Arrays.fill(isPrime,1);
		int i = 2;
		while(i * i <= n)
			if(isPrime[i] = 1)
			{
				for(int j = 2*i;j<n;j+=i)
					isPrime[j] = 0;
				i += 1;
			}
		for(int i = 2;i<n;i++)
			if(isPrime[i] == 1)
				res = (res*power(i,largestPower(n,i),p)) % p;
		return res;
	}
}