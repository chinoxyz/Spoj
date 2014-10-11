import java.util.Scanner;
import java.io.*;
import java.math.*;
import java.math.BigInteger;


class PAYING {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\PAYING.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			int cases,ans;
			BigInteger n,temp;
			cases=Integer.parseInt(br.readLine());
			
			while(cases>0)
			{
				ans=0;
				--cases;
				n=new BigInteger(br.readLine());
				temp=BigInteger.ONE;
				
				while(true)
				{
					if(temp.compareTo(n)>0)
					{
						break;
					}
					++ans;
					n=n.subtract(temp);
					temp=temp.multiply(BigInteger.valueOf(2));
				}
				
				while(true)
				{
					if(n.compareTo(BigInteger.ZERO)<=0)
					{
						break;
					}
					
					if(n.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ONE)==0)
					{
						++ans;
					}
					n=n.divide(BigInteger.valueOf(2));
				}
				
				System.out.println(ans);
			}
			
		}
		catch(Exception e)
		{
			
		}
	}

}
