import java.io.*;
import java.math.BigInteger;


class MINNUM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\MINNUM.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			BigInteger NINE=new BigInteger("9");
			BigInteger MONE=new BigInteger("-1");
			
			while(true)
			{
				BigInteger a=new BigInteger(br.readLine());
				
				if(a.equals(MONE))
				{
					break;
				}
				
				BigInteger ret=a.divide(NINE);
				if(a.mod(NINE)!=BigInteger.ZERO)
				{
					ret=ret.add(BigInteger.ONE);
				}
				
				System.out.println(ret);
				
			}
			

			
		}
		catch(Exception e)
		{
			
		}

	}

}
