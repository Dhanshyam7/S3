import java.io.*;
public class file
{
   public static void main(String args[])
   {
      BufferedReader read=new BufferedReader(new InputStreamReader(System.in));
      System.out.println("enter file name\n");
      try
      {  String str=read.readLine();
         FileWriter writer= new FileWriter(str);
	 System.out.println("enter content\n");
	 String c=read.readLine();
	 writer.write(c);
	 writer.close();
	 System.out.println("file written");

	 FileReader reader=new FileReader(str);
	 char ch[]=new  char[100] ;
	 reader.read(ch);
	 System.out.println(ch);
	 System.out.println("file read");
	 reader.close();
      }
      catch(IOException e)
      {
         System.out.println(e.getMessage());
      }
   }
}
