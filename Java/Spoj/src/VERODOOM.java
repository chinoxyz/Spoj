import java.io.*;
import java.util.*;
import java.math.*;
import java.security.*;


class VERODOOM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\VERODOOM.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			int cases=Integer.parseInt(br.readLine());
			
			while(cases-- >0)
			{
				BigInteger n=new BigInteger(br.readLine());
				n=n.multiply(n.add(BigInteger.ONE)).multiply(n.add(new BigInteger("2"))).divide(new BigInteger("2"));
				System.out.println(n);
			}

			
		}
		catch(Exception e)
		{
			
		}

	}

}
