
import java.io.*;
import java.io.FileWriter;
import java.io.FileReader;
public class filecpy
{
   public static void main(String[] args)
   {
      int i;
      try
      {
         BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
         System.out.println("enter the source filename");
         String filename1=b.readLine();
         System.out.println("enter the destination filename ");
         String filename2=b.readLine();
         FileWriter writer=new FileWriter(filename2); 
         FileReader reader=new FileReader(filename1);
         while((i=reader.read())!=-1)
         {
            writer.write((char)i);
            System.out.print((char)i);
         }
         writer.close();
         reader.close();
      }
      catch(Exception e)
      {
         System.out.println("error");
      }
   }
}


