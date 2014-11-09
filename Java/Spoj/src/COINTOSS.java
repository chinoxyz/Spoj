import java.io.*;
import java.math.BigInteger;


class COINTOSS {

	public static void main(String[] args) {
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\COINTOSS.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			int cases=Integer.parseInt(br.readLine());
			
			
			while(cases-- >0)
			{
				int n,m;
				
				String s[]=br.readLine().split(" ");
				n=Integer.parseInt(s[0]);
				m=Integer.parseInt(s[1]);
				
				if(n<=m)
				{
					System.out.println("0.00");
				}
				else
				{
					
					BigInteger twoo=new BigInteger("2");
					BigInteger a=twoo.pow(n+1);
					BigInteger b=twoo.pow(m+1);
					System.out.print(a.subtract(b));
					System.out.println(".00");
				}
				
			}
			

			
		}
		catch(Exception e)
		{
			
		}

	}

}
