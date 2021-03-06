import java.io.*;
import java.util.*;
import java.math.*;


class KPEQU {
	static int MAXN=10001;
	static int arr[]=new int[MAXN];
	static ArrayList<Integer> primes=new ArrayList<Integer>();
	
	static void sieve()
	{
		int sq=(int)Math.sqrt(MAXN);
		
		for(int i=3;i<=sq;i+=2)
		{
			if(arr[i]==0)
			{
				for(int j=i*i;j<MAXN;j+=i)
				{
					arr[j]=1;
				}
			}
		}
		
		primes.add(2);
		
		for(int i=3;i<MAXN;i+=2)
		{
			if(arr[i]==0)
			{
				primes.add(i);
			}
		}
		
		
	}
	
	static void solve(int n)
	{
		int i=0;
		BigInteger ans=new BigInteger("1");
		
		while(i<primes.size() && (n/primes.get(i))>0)
		{
			int ct=0;
			
			int ti=n;
			int td=primes.get(i);
			int tx=td;
			
			while(ti/td>0)
			{
				ct+=ti/td;
				td*=tx;
			}
			
			ans=ans.multiply(new BigInteger(Integer.toString(2*ct+1)));
			
			
			++i;
		}
		
		
		System.out.println(ans);
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\KPEQU.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			sieve();
			
			while(true)
			{
				int n=Integer.parseInt(br.readLine());
				if(n==0)
				{
					break;
				}
				solve(n);
				
			}
		}
		catch(Exception e)
		{
			
		}

	}

}
