import java.io.*;
public class bytesum
{
   public static void main(String args[])
   {  DataOutputStream dw=null;
      DataInputStream dr=null;
      try
      {
	 FileOutputStream file= new FileOutputStream("file.bin");
	 dw=new DataOutputStream(file);
	 dw.writeInt(5);
	 dw.writeInt(8);
	 dw.writeInt(6);
	 dw.close();

	 FileInputStream Ifile= new FileInputStream("file.bin");
         dr=new DataInputStream(Ifile);
	 int sum=0,temp;
	 while((temp=dr.read())!= -1)
	 {
	    sum=sum+temp;
	 }
	 dr.close();
	 System.out.println("sum:"+sum);
      }
      catch(Exception e)
	{System.out.println(e);}
   }
}
