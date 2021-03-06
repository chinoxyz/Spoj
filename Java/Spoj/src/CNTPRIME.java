import java.io.*;
import java.math.*;
import java.util.*;

class CNTPRIME {
	
	public static int MAXN=10003;
	public static int MAXV=1000003;
	
	public static BitSet primes=new BitSet(MAXV);
	public static BitSet arr=new BitSet(MAXN);
	static int n;
	static int q;
	static BitSet tb;
	
	static void pree()
	{
		//primes.set(0,MAXN);
		int i,j;
		for(i=3;i*i<MAXV;i+=2)
		{
			if(!primes.get(i))
			{
				for(j=i*i;j<MAXV;j+=i)
				{
					primes.set(j);
				}
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		pree();
		
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\CNTPRIME.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			int cases;
			cases=Integer.parseInt(br.readLine());
			int i;
			int x,y,v;
			int ret;
			int ti;
			
			
			
			for(int t=1;t<=cases;++t)
			{
				
				arr.clear();
				
				String a[]=br.readLine().split(" ");
				
				n=Integer.parseInt(a[0]);
				q=Integer.parseInt(a[1]);
				
				
				String b[]=br.readLine().split(" ");
				
				
				
				for(i=1;i<=n;++i)
				{
					ti=Integer.parseInt(b[i-1]);
					//System.out.println(ti);
					if(ti==2 || (!primes.get(ti) && (ti%2>0)))
					{
						arr.set(i);
					}
				}
				
				System.out.println("Case "+t+":");
				while(q-- > 0)
				{
					
					String c[]=br.readLine().split(" ");
					
					if(c[0].equals("1"))
					{
						x=Integer.parseInt(c[1]);
						y=Integer.parseInt(c[2]);
						
						tb=(BitSet)arr.clone();
						arr.clear(0,x);
						arr.clear(y+1,MAXN);
						
						System.out.println(arr.cardinality());
						arr=(BitSet)tb.clone();
						
					}
					else
					{
						x=Integer.parseInt(c[1]);
						y=Integer.parseInt(c[2]);
						v=Integer.parseInt(c[3]);
						
						if(v==2 || (!primes.get(v) && (v%2>0)))
						{
							arr.set(x,y+1);
						}
						else
						{
							arr.clear(x,y+1);
						}
					}
				}
				
			}			
		}
		catch(Exception e)
		{
			
		}

	}

}
