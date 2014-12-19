import java.util.*;
import java.math.*;
import java.io.*;

class EQU2 {

	static BigInteger ONE=BigInteger.ONE;
    static BigInteger ZERO=BigInteger.ZERO;
    
    public static BigInteger V(int x)
    {
        return BigInteger.valueOf(x);
    }
    public static void main(String[] args) 
	{
    	try
    	{
	    	Scanner S=new Scanner(new BufferedReader(new FileReader(".\\Text\\EQU2.txt")));
	        //Scanner S=new Scanner(System.in);
	        int T;
	        T=S.nextInt();
	        while(T--!=0)
	        {
	            BigInteger p0,p1,p2,q0,q1,q2,g0,g1,h0,h1,a,a0,n;
	            n=S.nextBigInteger();
	            p0=ZERO; p1=ONE;
	            q0=ONE; q1=ZERO;
	            a0=a=V((int)Math.sqrt(n.intValue()));
	            g0=ZERO; h0=ONE;
	            while(true)
	            {
	                g1=ZERO.subtract(g0).add(a.multiply(h0));
	                h1=n.subtract(g1.multiply(g1)).divide(h0);
	                p2=a.multiply(p1).add(p0);
	                q2=a.multiply(q1).add(q0);
	                a=g1.add(a0).divide(h1);
	                if(p2.multiply(p2).subtract(n.multiply(q2).multiply(q2)).compareTo(ONE)==0)
	                {
	                    break;
	                }
	                p0=p1; p1=p2;
	                q0=q1; q1=q2;
	                g0=g1; h0=h1;
	            }
	            System.out.print(p2);
	            System.out.print(' ');
	            System.out.println(q2);
	        }
    	}
    	catch(Exception e)
    	{
    		
    	}
    }

}
