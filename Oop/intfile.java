//write and read integer in a file ,add the sum and raise exception if greater than 100 or negative number
import java.io.*;
class GreaterException extends Exception
{
    GreaterException(String msg)
    {
        super(msg);
    }
}
class NegativeException extends Exception
{
    NegativeException(String msg)
    {
        super(msg);
    }
}
public class Main
{
    public static void main(String args[]) throws IOException,GreaterException,NegativeException
    {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        FileWriter w;
        try
        {
            String file=br.readLine();
            File f=new File(file);
            w= new FileWriter(f);
            for(int i=0;i<5;i++)
            {
                String num= br.readLine();
                w.write(num+"\n");
            }
            w.flush();
            w.close();
            FileReader r=new FileReader(f);
            BufferedReader rb= new BufferedReader(r);
            String c;
            int sum=0;
            while((c=rb.readLine())!=null)
            {   
                System.out.println(c);
                sum+=Integer.parseInt(c);
            }
            System.out.println(sum);
            if (sum>100)
                throw new GreaterException("greater than 100");
                
            else if (sum<0)
                throw new NegativeException("negative");
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}