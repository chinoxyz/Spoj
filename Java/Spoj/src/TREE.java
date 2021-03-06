import java.io.*;
import java.math.BigInteger;


class TREE {
	
	static int MAXN=33;
	static int MAXD=17;
	static int MAXD2=17;
	static int MAXL=999999;
	
	static BigInteger dp[][]=new BigInteger[MAXN][MAXD2];
	static BigInteger summ[][]=new BigInteger[MAXN][MAXD2];
	static BigInteger TWO=new BigInteger("2");
	static int tcc=0;
	static int nl;
	
	static BigInteger factt[][]=new BigInteger[MAXN][MAXN];
	
	
	static BigInteger bPoww(BigInteger numm,int p)
	{
		BigInteger ret=BigInteger.ONE;
		
		while(p>0)
		{
			
			if((p&1)>0)
			{
				ret=ret.multiply(numm);
			}
			p>>=1;
			
			numm=numm.multiply(numm);
		}
		
		
		
		return ret;
	}
	
	
	static void pree()
	{
		int i,j;
		int k;
		int ct;
		for(i=0;i<MAXD2;++i)
		{
			dp[1][i]=BigInteger.ONE;
		}
		
		for(i=2;i<MAXN;++i)
		{
			//System.out.println("TTTTT");
			dp[i][0]=dp[i][1]=summ[i][0]=BigInteger.ONE;
			summ[i][1]=TWO;
			BigInteger I=new BigInteger(i+"");
			nl=i*i;
			for(j=2;j<MAXD;++j)
			{
				nl*=i;
				
				
				if(nl>MAXL)
				{
					break;
				}
				
				dp[i][j]=BigInteger.ZERO;
				
				BigInteger p1=dp[i][j-1];
				BigInteger p2=summ[i][j-1];
				
				dp[i][j]=dp[i][j].subtract(bPoww(p2.subtract(p1),i));
				dp[i][j]=dp[i][j].add(bPoww(p2,i));
				
				summ[i][j]=summ[i][j-1].add(dp[i][j]);
			}
		}		
	}
	
	public static void main(String[] args) {
		
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\TREE.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			pree();
			int n,d;
			
			while(true)
			{		
				String a[]=br.readLine().split(" ");
				n=Integer.parseInt(a[0]);
				d=Integer.parseInt(a[1]);
				if(n+d==0)
				{
					break;
				}
				
				System.out.println(n+" "+d+" "+dp[n][d]);
			}			
		}
		catch(Exception e)
		{
			
		}	
	}
}






