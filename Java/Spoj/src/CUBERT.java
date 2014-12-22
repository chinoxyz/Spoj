import java.io.*;
import java.math.*;


class CUBERT {
	
	public static BigInteger TWO=new BigInteger("2");
	public static BigDecimal EPS=new BigDecimal("1e-12");
	public static BigDecimal TD=new BigDecimal("2");
	public static BigDecimal THD=new BigDecimal("3");
	
	public static BigInteger biint(BigInteger n)
	{
		BigInteger l=BigInteger.ONE;
		BigInteger r=n;
		BigInteger midd;
		while(l.compareTo(r)<0)
		{
			midd=l.add(r).add(BigInteger.ONE).divide(TWO);
			if(midd.pow(3).compareTo(n)<=0)
			{
				l=midd;
			}
			else
			{
				r=midd.subtract(BigInteger.ONE);
			}
		}
		
		if(n.compareTo(BigInteger.ONE)<0)
		{
			l=BigInteger.ZERO;
		}
		
		return l;
	}
	
	public static BigDecimal calc(BigDecimal midd,BigDecimal a)
	{
		return midd.multiply(midd.multiply(midd.add(a.multiply(THD))).add(THD.multiply(a).multiply(a)));
	}
	
	public static BigDecimal bidec(BigDecimal x,BigDecimal a)
	{
		BigDecimal l=BigDecimal.ZERO;
		BigDecimal r=BigDecimal.ONE;
		BigDecimal midd;
		
		while(r.subtract(l).compareTo(EPS)>0)
		{
			midd=l.add(r).divide(TD);
			
			if(calc(midd,a).compareTo(x)<=0)
			{
				
				l=midd;
			}
			else
			{
				r=midd;
			}
		}
		return l;
	}
	
	public static void solve(BigDecimal n)
	{
		BigInteger ni=n.toBigInteger();
		BigInteger integg=biint(ni);
		BigDecimal id=new BigDecimal(integg);
		BigDecimal dec=bidec(n.subtract(id.pow(3)),id);
		dec=dec.setScale(10, BigDecimal.ROUND_DOWN);
		BigDecimal ans=id.add(dec);
		ans=ans.setScale(10, BigDecimal.ROUND_DOWN);
		
		int ct=0;
		
		String l=integg.toString();
		String r=dec.toPlainString();
		for(int i=0;i<l.length();++i)
		{
			ct+=l.charAt(i)-'0';
		}
		
		for(int i=2;i<r.length();++i)
		{
			ct+=r.charAt(i)-'0';
		}
		ct%=10;
		System.out.println(ct+" "+ans);
	}
	
	
	public static boolean checkkNumm(String s)
	{
		for(int i=0;i<s.length();++i)
		{
			if(s.charAt(i)<'0' || s.charAt(i)>'9')
			{
				return false;
			}
		}
		
		
		
		return true;
	}
	
	public static void main(String[] args) {
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\CUBERT.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			String s;
			int cases;
			BigDecimal n;
			int i;
			cases=0;
			boolean fl=false;
			
			while(true)
			{
				s=br.readLine();
				s.trim();
				if(s.equals(""))
				{
					continue;
				}
				
				String sarr[]=s.split(" ");		
				
				for(i=0;i<sarr.length;++i)
				{
					sarr[i].trim();
					if(sarr[i].equals(" "))
					{
						continue;
					}
					if(!checkkNumm(sarr[i]))
					{
						continue;
					}
					cases=Integer.parseInt(sarr[i]);
					fl=true;
				}
				
				for(++i;i<sarr.length;++i)
				{
					sarr[i].trim();
					if(sarr[i].equals(""))
					{
						continue;
					}
					if(!checkkNumm(sarr[i]))
					{
						continue;
					}
					--cases;
					n=new BigDecimal(sarr[i]);
					solve(n);
				}
				
				if(fl)
				{
					break;
				}				
			}
			
			
			
			while(true)
			{
				if(cases==0)
				{
					break;
				}
				s=br.readLine();
				s.trim();
				if(s.equals(""))
				{
					continue;
				}
				String saarr[]=s.split(" ");
				
				for(i=0;i<saarr.length;++i)
				{
					saarr[i].trim();
					if(saarr[i].equals(""))
					{
						continue;
					}
					
					if(!checkkNumm(saarr[i]))
					{
						continue;
					}
					--cases;
					n=new BigDecimal(saarr[i]);
					solve(n);
				}
						
			}
			
			//System.out.println("DDDD");
			
		}
		catch(Exception e)
		{
			
		}
	}

}
