import java.util.ArrayList;
import java.util.Arrays;
public class PrimeSieve
{
	public ArrayList<Integer> Sieve(int n)
	{
		boolean[] primes = new boolean[n+1];
		Arrays.fill(primes, Boolean.TRUE);
		int p = 2;
		while(p * p <= n)
		{
			if(primes[p])
				for(int i = p*p;i<n+1;i+=p)
					primes[i] = false;
			p++;
		}
		ArrayList<Integer> myList = new ArrayList<>();
		for(int i = 2;i<n;i++)
			if(primes[i]) myList.add(i);
		return myList;
	}
}
//Prime sieve, generates primes under n