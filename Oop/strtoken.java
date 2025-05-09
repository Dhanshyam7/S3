import java.util.*;
import java.io.*;
public class strtoken
{
   public static void main(String args[])
   {
      try
      {
         BufferedReader r=new BufferedReader (new InputStreamReader(System.in));
	 System.out.println("enter line of integers");
	 String num=r.readLine();
	 StringTokenizer st= new StringTokenizer(num);
	 System.out.println("printing each integer");
	 int sum=0;
	 while (st.hasMoreTokens())
	 {  String str=st.nextToken();
	    System.out.println(str);
	    sum+=Integer.valueOf(str);
	 }
	 System.out.println("sum is "+ sum);
      }
      catch(Exception e)
      {}
   }
}
