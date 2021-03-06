import java.io.*;
import java.math.BigInteger;


class NUMPLAY {
	static int MAXN=10001;
	static BigInteger dp[][]=new BigInteger[MAXN][10];
	static int arr[]={1,3,5,7};
	
	
	public static void pree()
	{
		int i;
		
		for(i=0;i<4;++i)
		{
			dp[0][arr[i]]=BigInteger.ZERO;
			dp[1][arr[i]]=BigInteger.ONE;
		}
		
		for(i=2;i<MAXN;++i)
		{
			dp[i][3]=dp[i-1][1].add(dp[i-1][7]);
			dp[i][1]=dp[i-1][3];
			dp[i][5]=dp[i-1][3].add(dp[i-1][7]);
			dp[i][7]=dp[i-1][5];
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		pree();
		
		try
		{
			//System.out.println("DDD");
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\NUMPLAY.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			int cases;
			cases=Integer.parseInt(br.readLine());
			int n;
			BigInteger ret;
			while(cases-- >0)
			{
				//System.out.println("DDD");
				n=Integer.parseInt(br.readLine());
				
				ret=dp[n][1].add(dp[n][3]).add(dp[n][5]).add(dp[n][7]);
				
				System.out.println(ret+"\n");
				
			}			
		}
		catch(Exception e)
		{
			
		}

	}

}
